/*
  Copyright (C) 2024  Selwin van Dijk

  This file is part of signalbackup-tools.

  signalbackup-tools is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  signalbackup-tools is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with signalbackup-tools.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "desktopdatabase.ih"

bool DesktopDatabase::init()
{
  if (d_configdir.empty() || d_databasedir.empty())
    std::tie(d_configdir, d_databasedir) = getDesktopDir();

  // check if a wal (Write-Ahead Logging) file is present in path, and warn user to (cleanly) shut Signal Desktop down
  if (!d_ignorewal &&
      bepaald::fileOrDirExists(d_configdir + "/db.sqlite-wal"))
  {
    // warn
    Logger::error("Found Sqlite-WAL file (write-ahead logging).\n"
                  "Make sure Signal Desktop is cleanly shut down.");
    // << " or pass --ignorewall"?
    return false;
  }

  // decrypt the database
  d_cipherdb.reset(new SqlCipherDecryptor(d_configdir, d_databasedir, d_cipherversion));
  if (!d_cipherdb->ok())
    return false;

  // get the decrypted data
  auto [data, size] = d_cipherdb->data(); // unsigned char *, uint64_t

  // disable WAL (Write-Ahead Logging) on database, reading from memory
  // otherwise will not work see https://www.sqlite.org/fileformat.html
  if (data[0x12] == 2)
    data[0x12] = 1;
  if (data[0x13] == 2)
    data[0x13] = 1;

  std::pair<unsigned char *, uint64_t> desktopdata = {data, size};
  d_database = MemSqliteDB(&desktopdata);
  if (!d_database.ok())
  {
    Logger::error("Failed to open database");
    return false;
  }

  return true;
}

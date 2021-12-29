/*
    Copyright (C) 2019-2021  Selwin van Dijk

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

#ifndef ARGS_H_
#define ARGS_H_

#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <utility>

class Arg
{
  bool d_ok;
  size_t d_positionals;
  size_t d_maxpositional;
  std::string d_input;
  std::string d_password;
  std::vector<int> d_importthreads;
  std::vector<int> d_limittothreads;
  std::string d_output;
  std::string d_opassword;
  std::string d_source;
  std::string d_sourcepassword;
  bool d_generatefromtruncated;
  std::vector<long long int> d_croptothreads;
  std::vector<std::string> d_croptodates;
  std::vector<std::string> d_mergerecipients;
  std::vector<std::string> d_mergegroups;
  std::vector<std::string> d_sleepyh34d;
  std::vector<std::pair<std::string,std::string>> d_exportcsv;
  std::string d_exportxml;
  std::vector<std::string> d_runsqlquery;
  std::vector<std::string> d_runprettysqlquery;
  std::vector<std::string> d_limitcontacts;
  bool d_assumebadframesizeonbadmac;
  std::vector<long long int> d_editattachmentsize;
  std::string d_dumpdesktopdb;
  std::string d_dumpmedia;
  std::string d_dumpavatars;
  std::string d_hhenkel;
  std::string d_importcsv;
  std::vector<std::pair<std::string,std::string>> d_mapcsvfields;
  std::string d_importwachat;
  std::string d_setwatimefmt;
  std::string d_setselfid;
  bool d_onlydb;
  bool d_overwrite;
  bool d_listthreads;
  bool d_editgroupmembers;
  bool d_showprogress;
  bool d_removedoubles;
  bool d_fast;
  bool d_reordermmssmsids;
  bool d_stoponbadmac;
  bool d_verbose;
  long long int d_strugee;
  long long int d_strugee3;
  bool d_ashmorgan;
  bool d_strugee2;
  long long int d_hiperfall;
  bool d_deleteattachments;
  std::vector<long long int> d_limitdeletetothreads;
  std::string d_onlydeletebefore;
  std::string d_onlydeleteafter;
  long long int d_limitdeletetosize;
  std::vector<std::string> d_limitdeletetotypes;
 public:
  Arg(int argc, char *argv[]);
  inline Arg(Arg const &other) = delete;
  inline Arg &operator=(Arg const &other) = delete;
  inline bool ok() const;
  inline std::string const &input() const;
  inline std::string const &password() const;
  inline std::vector<int> const &importthreads() const;
  inline std::vector<int> const &limittothreads() const;
  inline std::string const &output() const;
  inline std::string const &opassword() const;
  inline std::string const &source() const;
  inline std::string const &sourcepassword() const;
  inline bool generatefromtruncated() const;
  inline std::vector<long long int> const &croptothreads() const;
  inline std::vector<std::string> const &croptodates() const;
  inline std::vector<std::string> const &mergerecipients() const;
  inline std::vector<std::string> const &mergegroups() const;
  inline std::vector<std::string> const &sleepyh34d() const;
  inline std::vector<std::pair<std::string,std::string>> const &exportcsv() const;
  inline std::string const &exportxml() const;
  inline std::vector<std::string> const &runsqlquery() const;
  inline std::vector<std::string> const &runprettysqlquery() const;
  inline std::vector<std::string> const &limitcontacts() const;
  inline bool assumebadframesizeonbadmac() const;
  inline std::vector<long long int> const &editattachmentsize() const;
  inline std::string const &dumpdesktopdb() const;
  inline std::string const &dumpmedia() const;
  inline std::string const &dumpavatars() const;
  inline std::string const &hhenkel() const;
  inline std::string const &importcsv() const;
  inline std::vector<std::pair<std::string,std::string>> const &mapcsvfields() const;
  inline std::string const &importwachat() const;
  inline std::string const &setwatimefmt() const;
  inline std::string const &setselfid() const;
  inline bool onlydb() const;
  inline bool overwrite() const;
  inline bool listthreads() const;
  inline bool editgroupmembers() const;
  inline bool showprogress() const;
  inline bool removedoubles() const;
  inline bool fast() const;
  inline bool reordermmssmsids() const;
  inline bool stoponbadmac() const;
  inline bool verbose() const;
  inline long long int strugee() const;
  inline long long int strugee3() const;
  inline bool ashmorgan() const;
  inline bool strugee2() const;
  inline long long int hiperfall() const;
  inline bool deleteattachments() const;
  inline std::vector<long long int> const &limitdeletetothreads() const;
  inline std::string const &onlydeletebefore() const;
  inline std::string const &onlydeleteafter() const;
  inline long long int limitdeletetosize() const;
  inline std::vector<std::string> const &limitdeletetotypes() const;
 private:
  template <typename T>
  bool ston(T *t, std::string const &str) const;
  bool parseArgs(std::vector<std::string> const &args);
  inline bool parseStringList(std::string const &strlist, std::vector<std::string> *list) const;
  template <typename T, typename U>
  inline bool parsePairList(std::string const &pairlist, std::string const &delim, std::vector<std::pair<T, U>> *list, std::string *error) const;
  template <typename T>
  bool parseNumberList(std::string const &strlist, std::vector<T> *list) const;
  template <typename T, typename U>
  bool parsePair(std::string const &token, std::string const &delim, std::pair<T, U> *pair, std::string *error) const;
  template <typename T>
  bool parseNumberListToken(std::string const &token, std::vector<T> *list) const;
  void usage() const;
};

inline std::string const &Arg::input() const
{
  return d_input;
}

inline std::string const &Arg::password() const
{
  return d_password;
}

inline std::vector<int> const &Arg::importthreads() const
{
  return d_importthreads;
}

inline std::vector<int> const &Arg::limittothreads() const
{
  return d_limittothreads;
}

inline std::string const &Arg::output() const
{
  return d_output;
}

inline std::string const &Arg::opassword() const
{
  return d_opassword;
}

inline std::string const &Arg::source() const
{
  return d_source;
}

inline std::string const &Arg::sourcepassword() const
{
  return d_sourcepassword;
}

inline bool Arg::generatefromtruncated() const
{
  return d_generatefromtruncated;
}

inline std::vector<long long int> const &Arg::croptothreads() const
{
  return d_croptothreads;
}

inline std::vector<std::string> const &Arg::croptodates() const
{
  return d_croptodates;
}

inline std::vector<std::string> const &Arg::mergerecipients() const
{
  return d_mergerecipients;
}

inline std::vector<std::string> const &Arg::mergegroups() const
{
  return d_mergegroups;
}

inline std::vector<std::string> const &Arg::sleepyh34d() const
{
  return d_sleepyh34d;
}

inline std::vector<std::pair<std::string,std::string>> const &Arg::exportcsv() const
{
  return d_exportcsv;
}

inline std::string const &Arg::exportxml() const
{
  return d_exportxml;
}

inline std::vector<std::string> const &Arg::runsqlquery() const
{
  return d_runsqlquery;
}

inline std::vector<std::string> const &Arg::runprettysqlquery() const
{
  return d_runprettysqlquery;
}

inline std::vector<std::string> const &Arg::limitcontacts() const
{
  return d_limitcontacts;
}

inline bool Arg::assumebadframesizeonbadmac() const
{
  return d_assumebadframesizeonbadmac;
}

inline std::vector<long long int> const &Arg::editattachmentsize() const
{
  return d_editattachmentsize;
}

inline std::string const &Arg::dumpdesktopdb() const
{
  return d_dumpdesktopdb;
}

inline std::string const &Arg::dumpmedia() const
{
  return d_dumpmedia;
}

inline std::string const &Arg::dumpavatars() const
{
  return d_dumpavatars;
}

inline std::string const &Arg::hhenkel() const
{
  return d_hhenkel;
}

inline std::string const &Arg::importcsv() const
{
  return d_importcsv;
}

inline std::vector<std::pair<std::string,std::string>> const &Arg::mapcsvfields() const
{
  return d_mapcsvfields;
}

inline std::string const &Arg::importwachat() const
{
  return d_importwachat;
}

inline std::string const &Arg::setwatimefmt() const
{
  return d_setwatimefmt;
}

inline std::string const &Arg::setselfid() const
{
  return d_setselfid;
}

inline bool Arg::onlydb() const
{
  return d_onlydb;
}

inline bool Arg::overwrite() const
{
  return d_overwrite;
}

inline bool Arg::listthreads() const
{
  return d_listthreads;
}

inline bool Arg::editgroupmembers() const
{
  return d_editgroupmembers;
}

inline bool Arg::showprogress() const
{
  return d_showprogress;
}

inline bool Arg::removedoubles() const
{
  return d_removedoubles;
}

inline bool Arg::fast() const
{
  return d_fast;
}

inline bool Arg::reordermmssmsids() const
{
  return d_reordermmssmsids;
}

inline bool Arg::stoponbadmac() const
{
  return d_stoponbadmac;
}

inline bool Arg::verbose() const
{
  return d_verbose;
}

inline long long int Arg::strugee() const
{
  return d_strugee;
}

inline long long int Arg::strugee3() const
{
  return d_strugee3;
}

inline bool Arg::ashmorgan() const
{
  return d_ashmorgan;
}

inline bool Arg::strugee2() const
{
  return d_strugee2;
}

inline long long int Arg::hiperfall() const
{
  return d_hiperfall;
}

inline bool Arg::deleteattachments() const
{
  return d_deleteattachments;
}

inline std::vector<long long int> const &Arg::limitdeletetothreads() const
{
  return d_limitdeletetothreads;
}

inline std::string const &Arg::onlydeletebefore() const
{
  return d_onlydeletebefore;
}

inline std::string const &Arg::onlydeleteafter() const
{
  return d_onlydeleteafter;
}

inline long long int Arg::limitdeletetosize() const
{
  return d_limitdeletetosize;
}

inline std::vector<std::string> const &Arg::limitdeletetotypes() const
{
  return d_limitdeletetotypes;
}

inline bool Arg::ok() const
{
  return d_ok;
}

template <typename T>
bool Arg::ston(T *t, std::string const &str) const
{
  std::istringstream iss(str);
  return !(iss >> *t).fail();
}

inline bool Arg::parseStringList(std::string const &strlist, std::vector<std::string> *list) const
{
  std::string tr = strlist;

  size_t start = 0;
  size_t pos = 0;
  while ((pos = tr.find(',', start)) != std::string::npos)
  {
    list->push_back(tr.substr(start, pos - start));
    start = pos + 1;
  }
  list->push_back(tr.substr(start));
  return true;
}

template <typename T, typename U>
inline bool Arg::parsePairList(std::string const &pairlist, std::string const &delim, std::vector<std::pair<T, U>> *list, std::string *error) const
{
  std::string tr = pairlist;

  size_t start = 0;
  size_t pos = 0;
  while ((pos = tr.find(',', start)) != std::string::npos)
  {
    std::pair<T, U> tmp;
    if (!parsePair(tr.substr(start, pos - start), delim, &tmp, error))
      return false;
    list->emplace_back(std::move(tmp));
    start = pos + 1;
  }
  std::pair<T, U> tmp;
  if (!parsePair(tr.substr(start), delim, &tmp, error))
    return false;
  list->emplace_back(std::move(tmp));
  return true;
}

template <typename T>
bool Arg::parseNumberList(std::string const &strlist, std::vector<T> *list) const
{
  std::string tr = strlist;

  size_t start = 0;
  size_t pos = 0;
  while ((pos = tr.find(',', start)) != std::string::npos)
  {
    if (!parseNumberListToken(tr.substr(start, pos - start), list))  // get&parse token
      return false;
    start = pos + 1;
  }
  if (!parseNumberListToken(tr.substr(start), list)) // get last bit
    return false;

  std::sort(list->begin(), list->end());

  return true;
}

template <typename T, typename U>
bool Arg::parsePair(std::string const &token, std::string const &delim, std::pair<T, U> *pair, std::string *error) const
{
  std::string::size_type pos = token.find(delim);
  if (pos == std::string::npos)
  {
    *error = "Delimiter not found.";
    return false;
  }

  std::string first = token.substr(0, pos);
  std::string second = token.substr(pos + 1);
  if (first.empty() || second.empty())
  {
    *error = "Empty field in pair.";
    return false;
  }

  if constexpr (std::is_same<T, std::string>::value)
    pair->first = first;
  else
  {
    if (!ston(&(pair->first), first))
    {
      *error = "Bad argument.";
      return false;
    }
  }

  if constexpr (std::is_same<U, std::string>::value)
    pair->second = second;
  else
  {
    if (!ston(&(pair->second), second))
    {
      *error = "Bad argument.";
      return false;
    }
  }

  return true;
}

template <typename T>
bool Arg::parseNumberListToken(std::string const &token, std::vector<T> *list) const
{
  size_t pos = 0;
  T beg = -1;

  // try and get first number
  if ((pos = token.find('-')) != std::string::npos)
  {
    if (!ston<T>(&beg, token.substr(0, pos)))
      return false;

    // then there must be a second number
    T end = -1;
    if (!ston<T>(&end, token.substr(pos + 1)))
      return false;

    if (beg > end)
      return false;
    for (int i = beg; i <= end ; ++i)
      list->push_back(i);
  }
  else
  {
    if (!ston<T>(&beg, token))
      return false;
    else
      list->push_back(beg);
  }

  return true;
}

#endif

//  Copyright (C) 2001-2003 Matthew Landauer. All Rights Reserved.
//  
//  This program is free software; you can redistribute it and/or modify it
//  under the terms of version 2 of the GNU General Public License as
//  published by the Free Software Foundation.
//
//  This program is distributed in the hope that it would be useful, but
//  WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  Further, any
//  license provided herein, whether implied or otherwise, is limited to
//  this program in accordance with the express provisions of the GNU
//  General Public License.  Patent licenses, if any, provided herein do not
//  apply to combinations of this program with other product or programs, or
//  any other product whatsoever.  This program is distributed without any
//  warranty that the program is delivered free of the rightful claim of any
//  third person by way of infringement or the like.  See the GNU General
//  Public License for more details.
//
//  You should have received a copy of the GNU General Public License along
//  with this program; if not, write the Free Software Foundation, Inc., 59
//  Temple Place - Suite 330, Boston MA 02111-1307, USA.
//
// $Id: UserGroup.cpp,v 1.6 2003/01/28 23:23:31 mlandauer Exp $

#include <pwd.h>
#include <unistd.h>
#include <grp.h>

#include "UserGroup.h"

namespace Sp {

UserGroup::UserGroup()
{
}

bool UserGroup::operator==(const UserGroup &g) const
{
  return (gid == g.gid);
}

UserGroup UserGroup::unixGid(gid_t g)
{
  UserGroup ret;
  ret.gid = g;
  return ret;
}

UserGroup UserGroup::current()
{
  UserGroup ret;
  ret.gid = getgid();
  return ret;
}

std::string UserGroup::getName() const
{
	struct group *e = getgrgid(gid);
	return (std::string(e->gr_name));
}

}
# Copyright (C) 2007 Rising Sun Pictures and Matthew Landauer
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

module ServersHelper
  def daemon_status(server)
    if server.daemon_alive?
      server.cache_complete? ? "up" : "incomplete"
    elsif server.daemon_version.nil?
      "down"
    else
      "unknown"
    end
  end

  def daemon_alive(server)
    if server.daemon_alive?
      true
    elsif server.daemon_version.nil?
      false
    else
      false
    end
  end

  def current_time(server)
    "The current time is #{Time.now.to_s}"
  end

  def daemon_info(server)
    server.get_daemon_status
  end

end

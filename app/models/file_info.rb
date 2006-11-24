class FileInfo < ActiveRecord::Base
  belongs_to :directory_info
  
  Stat = Struct.new(:mtime, :size, :uid, :gid)
  
  # Convenience method for setting all the fields associated with stat in one hit
  def stat=(stat)
    self.modified = stat.mtime
    self.size = stat.size
    self.uid = stat.uid
    self.gid = stat.gid
  end
  
  # Returns a "fake" Stat object with some of the same information as File::Stat
  def stat
    Stat.new(modified, size, uid, gid)
  end
  
  def FileInfo.find_by_directory_info_and_name(directory, name)
    FileInfo.find(:first, :conditions => ['directory_info_id = ? AND name = ?', directory.id, name])
  end
  
  def path
    directory_info.path
  end
end

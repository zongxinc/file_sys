#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "fs.h"
#include "disk.h"
#include <stdbool.h>
#include <stdint.h> 

struct super_block 
{
	uint16_t used_block_bitmap_count;
	uint16_t used_block_bitmap_offset;
	uint16_t inode_metadata_blocks;
	uint16_t inode_metadata_offset;
};

struct inode
{
	int file_type;
	int direct_offset;
	int single_direct;
	int double_direct;
	int triple_direct;
	int file_size;
};

struct directory_entry
{
	bool is_used;
	int inode_num;
	char *name;
};

struct file_descriptor
{
	bool is_used;
	int inode_num;
	int offset;
};

struct inode my_inode[8192];
struct file_descriptor my_file_descriptor[64];

int make_fs(const char *disk_name)
{
	if (make_disk(disk_name) != 0)
	{
		return -1;
	}

	if (open_disk(disk_name) != 0)
	{
		return -1;
	}
	//store metadata onto disk
	return 0;

}

int mount_fs(const char *disk_name)
{
	if (open_disk(disk_name) != 0)
	{
		return -1;
	}
	//store metadata from the disk
	return 0;
}

int umount_fs(const char *disk_name)
{
	//open?
	//write metadata to disk
	if (close_disk(disk_name) != 0)
	{
		return -1;
	}
	return 0;
}

int fs_open(const char *name)
{
	return 0;
}

int fs_close(int fildes)
{
	return 0;
}

int fs_create(const char *name)
{
	return 0;
}
int fs_delete(const char *name)
{
	return 0;
}
int fs_read(int fildes, void *buf, size_t nbyte)
{
	return 0;
}
int fs_write(int fildes, void *buf, size_t nbyte)
{
	return 0;
}
int fs_get_filesize(int fildes)
{
	return 0;
}
int fs_listfiles(char ***files)
{
	return 0;
}
int fs_lseek(int fildes, off_t offset)
{
	return 0;
}
int fs_truncate(int fildes, off_t length)
{
	return 0;
}
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
	char name[16];
};

struct file_descriptor
{
	bool is_used;
	int inode_num;
	int offset;
};

int blocks[8192];
struct inode my_inode[64];
struct file_descriptor my_file_descriptor[64];
struct directory_entry my_dir_entry[64];


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

	// struct inode root;
	// root.file_type = 1;
	// root.direct_offset = 3;
	// my_dir_entry[0].is_used = 1;
	// my_dir_entry[0].inode_num = 3;
	// char filename[] = "root";
	// memcpy(my_dir_entry[0].name, filename, sizeof(filename));


	// for (int i = 0; i < 64; i++)
	// {
	// 	my_inode[i].file_type = -1;
	// 	my_inode[i].direct_offset = -1;
	// 	my_inode[i].single_direct = -1;
	// 	my_inode[i].double_direct = -1;
	// 	my_inode[i].triple_direct = -1;
	// 	my_inode[i].file_size = -1;
	// }
	// char inode_buf[4096] = {0};
	// memcpy(inode_buf, my_inode, sizeof(my_inode));
	// block_write(1, inode_buf);

	// for (int i = 0; i < 8192; i++)
	// {
	// 	blocks[i] = 0;
	// }
	// blocks[0] = 1;
	// blocks[1] = 1;
	// char block_buf[4096] = {0};
	// memcpy(block_buf, blocks, sizeof(blocks));
	// block_write(2, block_buf);


	// struct super_block *mysuper;
	// mysuper->used_block_bitmap_count = 2;
	// mysuper->used_block_bitmap_offset = sizeof(blocks);
	// mysuper->inode_metadata_blocks = 1;
	// mysuper->inode_metadata_offset = sizeof(my_inode);
	// char buf[4096] = {0};
	// memcpy(buf, mysuper, sizeof(mysuper));
	// block_write(0, buf);
	// //store metadata onto disk
	return 0;

}

int mount_fs(const char *disk_name)
{
	if (open_disk(disk_name) != 0)
	{
		return -1;
	}
	//store metadata from the disk
	return -1;
}

int umount_fs(const char *disk_name)
{
	//open?
	//write metadata to disk
	if (close_disk(disk_name) != 0)
	{
		return -1;
	}
	return -1;
}

int fs_open(const char *name)
{
	return -1;
	//return file descriptor?
}

int fs_close(int fildes)
{
	return -1;
}

int fs_create(const char *name)
{
	return -1;
}
int fs_delete(const char *name)
{
	return -1;
}
int fs_read(int fildes, void *buf, size_t nbyte)
{
	return -1;
}
int fs_write(int fildes, void *buf, size_t nbyte)
{
	return -1;
}
int fs_get_filesize(int fildes)
{
	return -1;
}
int fs_listfiles(char ***files)
{
	return -1;
}
int fs_lseek(int fildes, off_t offset)
{
	return -1;
}
int fs_truncate(int fildes, off_t length)
{
	return -1;
}
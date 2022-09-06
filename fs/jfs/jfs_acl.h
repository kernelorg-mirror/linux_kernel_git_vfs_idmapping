/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 *   Copyright (C) International Business Machines  Corp., 2002
 */
#ifndef _H_JFS_ACL
#define _H_JFS_ACL

#ifdef CONFIG_JFS_POSIX_ACL

struct posix_acl *jfs_get_acl(struct inode *inode, int type, bool rcu);
static inline struct posix_acl *
jfs_get_dentry_acl(struct user_namespace *mnt_userns, struct dentry *dentry,
		   int type)
{
	return jfs_get_acl(d_inode(dentry), type, false);
}
int jfs_set_acl(struct user_namespace *mnt_userns, struct dentry *dentry,
		struct posix_acl *acl, int type);
int jfs_init_acl(tid_t, struct inode *, struct inode *);

#else

static inline int jfs_init_acl(tid_t tid, struct inode *inode,
			       struct inode *dir)
{
	return 0;
}

#endif
#endif		/* _H_JFS_ACL */

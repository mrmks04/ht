/* 
 *	HT Editor
 *	vfsview.h
 *
 *	Copyright (C) 1999-2002 Stefan Weyergraf (stefan@weyergraf.de)
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License version 2 as
 *	published by the Free Software Foundation.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program; if not, write to the Free Software
 *	Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef __VFSVIEW_H__
#define __VFSVIEW_H__

#include "htdialog.h"
#include "vfs.h"

/*
 *	class VfsListbox
 */

struct vfs_extra {
	pstat_t stat;
	char *name;
};

#define VFSV_FORMAT_MAX_COLS		64
#define VFSV_FORMAT_PROPERTIES	22

#define VfsListboxData ht_itext_listbox_data

class VfsListbox: public ht_itext_listbox {
protected:
	ht_list *vfs_list;
	Vfs *cvfs;
	char cdir[VFS_DIR_MAX+1];
	char cproto[VFS_PROTO_MAX+1];
/**/
	int dfmt_cols;
	int dfmt_props;
	int dfmt_prop2colidx[VFSV_FORMAT_MAX_COLS];
	int dfmt_prop[VFSV_FORMAT_MAX_COLS];
	int dfmt_quickfind;
/**/
	ht_text *show_pos;
	
/* overwritten */
	virtual	void			free_extra_data(void *extra_data);
/* new */
			void			renderEntry(char *buf, int bufsize, int dfmt, const char *filename, pstat_t stat);
			void			set_display_format(char *fmt);
	virtual	bool 		select_entry(void *entry);
			char *		translate_prop(char *fmt, int *type);
			void			reread();
public:
			void			init(bounds *b, ht_list *vfs_list, ht_text *show_pos);
	virtual	void			done();
/* overwritten */
	virtual	void			config_changed();
	virtual	void			handlemsg(htmsg *msg);
	virtual	void			update();
/* new */
			int			changeURL(const char *url);
			int			changeDir(const char *dir);
			const char *	getCurDir();
			const char *	getCurProto();
			Vfs *		getCurVfs();
};

/*
 *	class VfsListbox2
 */

class VfsListbox2: public VfsListbox {
public:
/**/
	virtual	bool select_entry(void *entry);
};

#endif /* __VFSVIEW_H__ */

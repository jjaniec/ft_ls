/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_ext_attr_acl.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:05:19 by jjaniec           #+#    #+#             */
/*   Updated: 2018/03/21 19:06:50 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Search if a directory entry has extended attributes or
** acl permissions specified
*/

void		ft_fill_ext_attr_acl(char *path, t_str_stats *f_stats)
{
	acl_t		acls;
	acl_entry_t	dummy;

	acls = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acls && acl_get_entry(acls, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acls);
		acls = NULL;
	}
	if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
		f_stats->perms_attr_acl = '@';
	else if (acls)
		f_stats->perms_attr_acl = '+';
}

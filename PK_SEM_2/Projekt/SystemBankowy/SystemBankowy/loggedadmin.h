#ifndef loggedadmin_H
#define loggedadmin_H
#include "structures.h"


/*

*/
void loggedadmin(Admin_list *alist, User_list *ulist, Admin *admin);

void ad_unlockuser(User_list *ulist);
void ad_unlockadmin(Admin_list *alist);
void ad_deleteadmin(Admin_list *alist, Admin *loggedadmin);
void ad_deleteuser(User_list *ulist);


#endif
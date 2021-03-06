/*** Copyright (c), The Regents of the University of California            ***
 *** For more information please refer to subStructFiles in the COPYRIGHT directory ***/
/* subStructFileReaddir.h
 */

#ifndef SUB_STRUCT_FILE_READDIR_HPP
#define SUB_STRUCT_FILE_READDIR_HPP

/* This is Object File I/O type API call */

#include "rods.hpp"
#include "rcMisc.hpp"
#include "procApiRequest.hpp"
#include "apiNumber.hpp"
#include "initServer.hpp"
#include "subStructFileRead.hpp"

#if defined(RODS_SERVER)
#define RS_SUB_STRUCT_FILE_READDIR rsSubStructFileReaddir
/* prototype for the server handler */
int
rsSubStructFileReaddir( rsComm_t *rsComm, subStructFileFdOprInp_t *subStructFileReaddirInp,
                        rodsDirent_t **rodsDirent );
int
_rsSubStructFileReaddir( rsComm_t *rsComm, subStructFileFdOprInp_t *subStructFileReaddirInp,
                         rodsDirent_t **rodsDirent );
int
remoteSubStructFileReaddir( rsComm_t *rsComm, subStructFileFdOprInp_t *subStructFileReaddirInp,
                            rodsDirent_t **rodsDirent, rodsServerHost_t *rodsServerHost );
#else
#define RS_SUB_STRUCT_FILE_READDIR NULL
#endif

/* prototype for the client call */
int
rcSubStructFileReaddir( rcComm_t *conn, subStructFileFdOprInp_t *subStructFileReaddirInp,
                        rodsDirent_t **rodsDirent );

#endif	/* SUB_STRUCT_FILE_READDIR_H */

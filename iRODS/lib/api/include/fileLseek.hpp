/**
 * @file  fileLseek.h
 *
 */

/*** Copyright (c), The Regents of the University of California            ***
 *** For more information please refer to files in the COPYRIGHT directory ***/
/* fileLseek.h - This file may be generated by a program or script
 */

#ifndef FILE_LSEEK_HPP
#define FILE_LSEEK_HPP

/* This is a low level file type API call */

#include "rods.hpp"
#include "rcMisc.hpp"
#include "procApiRequest.hpp"
#include "apiNumber.hpp"
#include "initServer.hpp"

/**
 * \var fileLseekInp_t
 * \brief Input struct for rcDataObjLseek and rsFileLseek operations
 * \since 1.0
 *
 * \remark none
 *
 * \note
 * Elements of fileLseekInp_t:
 * \li int fileInx - the opened file descriptor from
 *      rcFileOpen or rcFileCreate.
 * \li rodsLong_t offset - the roffset
 * \li int whence - Similar to lseek of UNIX. Valid values are:
 *        \n SEEK_SET - The offset is set to offset bytes.
 *        \n SEEK_CUR - The offset is set to its current location plus
 *             offset bytes.
 *        \n SEEK_END - The offset is set to the size of the file plus
 *             offset bytes.
 *
 * \sa none
 * \bug  no known bugs
 */

typedef struct FileLseekInp {
    int fileInx;
    rodsLong_t offset;
    int whence;
} fileLseekInp_t;

/**
 * \var fileLseekOut_t
 * \brief Output struct for rcDataObjLseek and rsFileLseek operations
 * \since 1.0
 *
 * \remark none
 *
 * \note
 * Elements of fileLseekOut_t:
 * \li offset - the resulting offset location in bytes from the beginning
 *        of the file.
 *
 * \sa none
 * \bug  no known bugs
 */

typedef struct FileLseekOut {
    rodsLong_t offset;
} fileLseekOut_t;

#define fileLseekInp_PI "int fileInx; double offset; int whence;"

#define fileLseekOut_PI "double offset;"

#if defined(RODS_SERVER)
#define RS_FILE_LSEEK rsFileLseek
/* prototype for the server handler */
int
rsFileLseek( rsComm_t *rsComm, fileLseekInp_t *fileLseekInp,
             fileLseekOut_t **fileLseekOut );
int
_rsFileLseek( rsComm_t *rsComm, fileLseekInp_t *fileLseekInp,
              fileLseekOut_t **fileLseekOut );
int
remoteFileLseek( rsComm_t *rsComm, fileLseekInp_t *fileLseekInp,
                 fileLseekOut_t **fileLseekOut, rodsServerHost_t *rodsServerHost );
#else
#define RS_FILE_LSEEK NULL
#endif

/* prototype for the client call */
#ifdef __cplusplus
extern "C" {
#endif
int
rcFileLseek( rcComm_t *conn, fileLseekInp_t *fileLseekInp,
             fileLseekOut_t **fileLseekOut );

#ifdef __cplusplus
}
#endif
#endif	/* FILE_LSEEK_H */

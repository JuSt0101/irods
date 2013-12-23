/* -*- mode: c++; fill-column: 132; c-basic-offset: 4; indent-tabs-mode: nil -*- */

// =-=-=-=-=-=-=-
// irods includes
#include "irods_database_manager.hpp"

namespace irods {
    // =-=-=-=-=-=-=-
    // database manager singleton
    database_manager db_mgr;

    // =-=-=-=-=-=-=-
    // public - Constructor
    database_manager::database_manager() {

    } // ctor

    // =-=-=-=-=-=-=-
    // public - Copy Constructor
    database_manager::database_manager( const database_manager& _rhs ) {
        plugins_ = _rhs.plugins_;

    } // cctor

    // =-=-=-=-=-=-=-
    // public - Destructor
    database_manager::~database_manager( ) {

    } // dtor

    // =-=-=-=-=-=-=-
    // public - retrieve a database plugin given its key
    error database_manager::resolve(
        std::string  _key,
        database_ptr& _value ) {

        if ( _key.empty() ) {
            return ERROR( SYS_INVALID_INPUT_PARAM, "empty key" );
        }

        if ( plugins_.has_entry( _key ) ) {
            _value = plugins_[ _key ];
            return SUCCESS();

        }
        else {
            std::stringstream msg;
            msg << "no database plugin found for name ["
                << _key
                << "]";
            return ERROR( SYS_INVALID_INPUT_PARAM, msg.str() );

        }

    } // resolve

    // =-=-=-=-=-=-=-
    // public - given a type, load up a database plugin
    error database_manager::init_from_type(
        const std::string& _type,
        const std::string& _key,
        const std::string& _inst,
        const std::string& _ctx,
        database_ptr&      _db ) {
        // =-=-=-=-=-=-=-
        // create the database plugin and add it to the table
        database_ptr ptr;
        error ret = load_database_plugin( ptr, _type, _inst, _ctx );
        if ( !ret.ok() ) {
            return PASSMSG( "Failed to load database plugin", ret );
        }

        plugins_[ _key ] = ptr;

        _db = plugins_[ _key ];

        return SUCCESS();

    } // init_from_type

}; // namespace irods



<?php
// *****************************************************************************
// Copyright 2003-2007 by A J Marston <http://www.tonymarston.net>
// Distributed under the GNU General Public Licence
// *****************************************************************************

// This file contains database access details and the standard connection function
$GLOBALS['dbms']   = 'ORACLE';      // database engine is Oracle
//$GLOBALS['dbms']   = 'pgsql';      // database engine is PostgreSQL
//$GLOBALS['dbms']   = 'mysql';     // database engine is MySql
//$GLOBALS['dbms']   = 'sqlsrv';     // database engine is SQL Server (Microsoft)

if ($GLOBALS['dbms'] == 'mysql') {
    $GLOBALS['dbhost'] = '//localhost/xe';

} elseif ($GLOBALS['dbms'] == 'sqlsrv') {
    // JOIN clauses in SQL Server require 'dbname.<schema>.tblname'
    $GLOBALS['SQLSRV_schema'] = 'dbo';

} elseif ($GLOBALS['dbms'] == 'pgsql') {
    // NOTE: with MYSQL there are tables withing databases, and within a single connection
    // it is possible to access tables in any database.
    // But with PostgreSQL there are tables within schemas within databases, and within
    // a single connection it is only possible to access a single database, but any number
    // of schemas within that database.
    // When using PostgreSQL you must supply a value for $PGSQL_dbname for the single database
    // connection, and what is known as 'dbname' to MySQL becomes 'schema' to PostgreSQL.
    $GLOBALS['dbhost']       = 'localhost';
    $GLOBALS['PGSQL_dbname'] = 'sample';

} else {
    $GLOBALS['dbhost'] = 'syncapse.com';
} // if

// NOTE: $dbprefix is for my web host (shared) where my databases are prefixed
// with my account name to keep them separate from other accounts.

if (preg_match('/^(127.0.0.1|localhost|desktop|laptop)$/i', $_SERVER['SERVER_NAME'])) {
    // this is for my PC
    $dbusername = 'p.bhatia@syncapse.com';
    $dbuserpass = 'sample';
    $dbprefix   = dbo;
    $http_server         = null;
    $https_server        = null;
    $https_server_suffix = null;
    $GLOBALS['log_xml_document'] = true;
} else {
    // this is for my web host
    $dbusername = 'pbhatia';
    $dbuserpass = '****';
    $dbprefix   = 'dbo';
    $http_server         = null;
    $https_server        = null;
    $https_server_suffix = null;
    $GLOBALS['log_xml_document'] = false;
} // if

?>
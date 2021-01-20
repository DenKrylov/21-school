<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define('DB_NAME', 'base');

/** MySQL database username */
define('DB_USER', 'admin');

/** MySQL database password */
define('DB_PASSWORD', 'admin');

/** MySQL hostname */
define('DB_HOST', 'localhost');

/** Database Charset to use in creating database tables. */
define('DB_CHARSET', 'utf8');

/** The Database Collate type. Don't change this if in doubt. */
define('DB_COLLATE', '');

define('FS_METHOD', 'direct');
/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'p2Hhh]L/[WS}ncNfO}oBBTL[z<DnQQYko^frRWC6L-kJWM?eiYDH]|dmaVSc0vT4');
define('SECURE_AUTH_KEY',  'SDWJ[|mgT |h%qj)/HcuMacrd`K YOknP~ZIZ.0Ui#11]-Z,fUPopyb| UZ WO%;');
define('LOGGED_IN_KEY',    'f4B`v_HC7G!iQn%miZBH^gr4jg`+l5<J@[?s&Dk&gfGN)P4KUXXy5-yDF-BxI01D');
define('NONCE_KEY',        'lPZE9ESg/V2uxs0BpeXZ8_CUTp8SJaGsI&BBHraodjH{|%y ~x9fafEn>%q9w$g8');
define('AUTH_SALT',        'S@,~z83(q|5]S^D2p8@gMA~bXy^ZsW96=8tYFaXO9@|PKgED@[MZ;wIf;7F+bbZ~');
define('SECURE_AUTH_SALT', 'y7A woD&R--cQ}|FBRh>Pv$ZaIftI[kU%1o|Ko27z&c#ha+1[o;-_xe;x8+ys.u]');
define('LOGGED_IN_SALT',   '9&#4l|DuypY7*mB=3i@X?2e8o7/Jd>>|+K}5DG{+^Pq<3*$DS^2kNX+z/8ghz?5:');
define('NONCE_SALT',       'mBgRYS(8NMaI9{P^mS6.pYGryU/sBXf iuwIYF3&bFDnmg=)-[d;DBzd?*U>Nh}o');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix  = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define('WP_DEBUG', false);

/* That's all, stop editing! Happy blogging. */

/** Absolute path to the WordPress directory. */
if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');

/** Sets up WordPress vars and included files. */
require_once(ABSPATH . 'wp-settings.php');

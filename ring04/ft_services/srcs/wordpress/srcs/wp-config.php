<?php

define( 'DB_NAME', 'monie' );

define( 'DB_USER', 'monie' );

define( 'DB_PASSWORD', 'qwerty' );

define( 'DB_HOST', 'mysql:3306');
define( 'WP_HOME', 'http://192.168.99.201:5050/' );
define( 'WP_SITEURL', 'http://192.168.99.201:5050/' );

define( 'DB_CHARSET', 'utf8' );

define( 'DB_COLLATE', '' );

define('FS_METHOD', 'direct');

define('AUTH_KEY',         '^dAAU7yh`djk2v%q:O`4i*hxD]vx$+Qgwkp,Lk* *xqgQl!L7Id~6)[Av/[o#9$Y');
define('SECURE_AUTH_KEY',  ')QIV|;dyAUD]h#,C{x9LUOm?6*x tC5>G%7[m|KzuHe|{N!ZLYx+e:2)nwcrc:y?');
define('LOGGED_IN_KEY',    '/5U:y~3NksS~!L$FjBf7XhCwl8QkVM]s6u[,D!s&pa;s%A+- &h5B.r`+%|RFu|V');
define('NONCE_KEY',        'Otw}x^b+;J4s`4Qvtsb1^o8~weQ1vJ%OqQ4bnW|+~:3.8P-l|Z-vnIysZVi9+8]L');
define('AUTH_SALT',        'leJ~4TO5N+-widRs;=?B+iO!OVX71]5ijwmt*XL(+Kv9i@k9k(wim~g7g{zJip^D');
define('SECURE_AUTH_SALT', ']UTg oF9C5sBw,ead^qHghks|%m}nroW2|RUbRe,ruxGYg;|gfT+q-]lTePo#[pP');
define('LOGGED_IN_SALT',   'q=(6`DY`u%-3%k~r<*4}8J3xbAz$S*hh)KL8M#IC*@-a+FXIOz#,y}:lW]!}T[bP');
define('NONCE_SALT',       'GGK{t2|H,P?|O:pnLY$(7{GF[E-2>^_&+br/Sl~erggzbyALOaai)9V3]Urr-!+|');

$table_prefix = 'wp_';

define( 'WP_DEBUG', true );

if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

require_once ABSPATH . 'wp-settings.php';
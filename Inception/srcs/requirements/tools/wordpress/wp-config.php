<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'mariadb' );

/** Database username */
define( 'DB_USER', 'wonjchoi' );

/** Database password */
define( 'DB_PASSWORD', '1234' );

/** Database hostname */
define( 'DB_HOST', 'localhost' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         '9o1r9s?<uUo{jF;9y+jnt}lS]W[5Vl%{Wb-pQS7>^F]v5(ldj1ALkED&Yna7rlTI' );
define( 'SECURE_AUTH_KEY',  ' B]8`/umT@*NypdRY*4Z^IhD?6TZ.%Z^{s-r{m5$JOkHx5QR`OURJM*O1-kI{-~|' );
define( 'LOGGED_IN_KEY',    'EHHT}m6R2Br(~xSt66)8@c0.$vp5_a[p_b&Zei|{g;P2`{-,{p~n#w07XSJeD89o' );
define( 'NONCE_KEY',        '(KUzi_OL)B9WwLLB(9tDmt8#7Si^2:}fG{HX5*AzYhe2{rqte0!K=T$?1#DzMR})' );
define( 'AUTH_SALT',        'pv=v] :2[1}EDgR)fX)`_M6>{ kkQF;/]!uV|05lSC)z2H@Mj6$& <F{,R4&PU^K' );
define( 'SECURE_AUTH_SALT', 'IYtaCwk6T_~C,Tx5N(2:IvYH[0O1M6;L$=bgj}};lK6C8]g?6QI<i/xKF,acAotM' );
define( 'LOGGED_IN_SALT',   '5{ZtK*Un}63a/Y]Kq] {j%s@{=$uL1xyYahFGi*0vbmFal<!7,Hb{{uYO~QQ.ofU' );
define( 'NONCE_SALT',       'k[Q5F owL=TWD`5$D5h(Ckmjg*:Rg0mWn9ehrkI23S_a l<~m/u+ec*f^$(,45Qs' );

/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';

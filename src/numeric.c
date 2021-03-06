/*
 *   Unreal Internet Relay Chat Daemon, src/numeric.c
 *   Copyright (C) 1992 Darren Reed
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 1, or (at your option)
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/** @file
 * @brief Numeric replies in the IRC protocol.
 */

#include "unrealircd.h"

/** Numeric replies */
static char *replies[] = {
/* 000 */ NULL,
/* 001    RPL_WELCOME */  ":Welcome to the %s IRC Network %s!%s@%s",
/* 002    RPL_YOURHOST */ ":Your host is %s, running version %s",
/* 003    RPL_CREATED */  ":This server was created %s",
/* 004    RPL_MYINFO */   "%s %s %s %s",
/* 005    RPL_ISUPPORT */ "%s :are supported by this server",
/* 006    RPL_MAP */      ":%s%-*s(%ld) %s",
/* 007    RPL_MAPEND */   ":End of /MAP",
/* 008    RPL_SNOMASK */  "%s :Server notice mask",
/* 009 */ NULL, /* ircu */
/* 010    RPL_REDIR */	  "%s %d :Please use this Server/Port instead",
/* 011 */ NULL,
/* 012 */ NULL,
/* 013 */ NULL,
/* 014 */ NULL, /* hybrid */
/* 015 */ NULL,
/* 016 */ NULL,
/* 017 */ NULL,
/* 018 */ NULL,
/* 019 */ NULL,
/* 020 */ NULL,
/* 021 */ NULL,
/* 022 */ NULL,
/* 023 */ NULL,
/* 024 */ NULL,
/* 025 */ NULL,
/* 026 */ NULL,
/* 027 */ NULL,
/* 028 */ NULL,
/* 029 */ NULL,
/* 030 */ NULL,
/* 031 */ NULL,
/* 032 */ NULL,
/* 033 */ NULL,
/* 034 */ NULL,
/* 035 */ NULL,
/* 036 */ NULL,
/* 037 */ NULL,
/* 038 */ NULL,
/* 039 */ NULL,
/* 040 */ NULL,
/* 041 */ NULL,
/* 042    RPL_YOURID */	"%s :your unique ID",
/* 043 */ NULL, /* ircnet */
/* 044 */ NULL,
/* 045 */ NULL,
/* 046 */ NULL,
/* 047 */ NULL,
/* 048 */ NULL,
/* 049 */ NULL,
/* 050 */ NULL, /* aircd */
/* 051 */ NULL, /* aircd */
/* 052 */ NULL,
/* 053 */ NULL,
/* 054 */ NULL,
/* 055 */ NULL,
/* 056 */ NULL,
/* 057 */ NULL,
/* 058 */ NULL,
/* 059 */ NULL,
/* 060 */ NULL,
/* 061 */ NULL,
/* 062 */ NULL,
/* 063 */ NULL,
/* 064 */ NULL,
/* 065 */ NULL,
/* 066 */ NULL,
/* 067 */ NULL,
/* 068 */ NULL,
/* 069 */ NULL,
/* 070 */ NULL,
/* 071 */ NULL,
/* 072 */ NULL,
/* 073 */ NULL,
/* 074 */ NULL,
/* 075 */ NULL,
/* 076 */ NULL,
/* 077 */ NULL,
/* 078 */ NULL,
/* 079 */ NULL,
/* 080 */ NULL,
/* 081 */ NULL,
/* 082 */ NULL,
/* 083 */ NULL,
/* 084 */ NULL,
/* 085 */ NULL,
/* 086 */ NULL,
/* 087 */ NULL,
/* 088 */ NULL,
/* 089 */ NULL,
/* 090 */ NULL,
/* 091 */ NULL,
/* 092 */ NULL,
/* 093 */ NULL,
/* 094 */ NULL,
/* 095 */ NULL,
/* 096 */ NULL,
/* 097 */ NULL,
/* 098 */ NULL,
/* 099 */ NULL,
/* 100 */ NULL,
/* 101 */ NULL,
/* 102 */ NULL,
/* 103 */ NULL,
/* 104 */ NULL,
/* 105    RPL_REMOTEISUPPORT */ "%s :are supported by this server",
/* 106 */ NULL,
/* 107 */ NULL,
/* 108 */ NULL,
/* 109 */ NULL,
/* 110 */ NULL,
/* 111 */ NULL,
/* 112 */ NULL,
/* 113 */ NULL,
/* 114 */ NULL,
/* 115 */ NULL,
/* 116 */ NULL,
/* 117 */ NULL,
/* 118 */ NULL,
/* 119 */ NULL,
/* 120 */ NULL,
/* 121 */ NULL,
/* 122 */ NULL,
/* 123 */ NULL,
/* 124 */ NULL,
/* 125 */ NULL,
/* 126 */ NULL,
/* 127 */ NULL,
/* 128 */ NULL,
/* 129 */ NULL,
/* 130 */ NULL,
/* 131 */ NULL,
/* 132 */ NULL,
/* 133 */ NULL,
/* 134 */ NULL,
/* 135 */ NULL,
/* 136 */ NULL,
/* 137 */ NULL,
/* 138 */ NULL,
/* 139 */ NULL,
/* 140 */ NULL,
/* 141 */ NULL,
/* 142 */ NULL,
/* 143 */ NULL,
/* 144 */ NULL,
/* 145 */ NULL,
/* 146 */ NULL,
/* 147 */ NULL,
/* 148 */ NULL,
/* 149 */ NULL,
/* 150 */ NULL,
/* 151 */ NULL,
/* 152 */ NULL,
/* 153 */ NULL,
/* 154 */ NULL,
/* 155 */ NULL,
/* 156 */ NULL,
/* 157 */ NULL,
/* 158 */ NULL,
/* 159 */ NULL,
/* 160 */ NULL,
/* 161 */ NULL,
/* 162 */ NULL,
/* 163 */ NULL,
/* 164 */ NULL,
/* 165 */ NULL,
/* 166 */ NULL,
/* 167 */ NULL,
/* 168 */ NULL,
/* 169 */ NULL,
/* 170 */ NULL,
/* 171 */ NULL,
/* 172 */ NULL,
/* 173 */ NULL,
/* 174 */ NULL,
/* 175 */ NULL,
/* 176 */ NULL,
/* 177 */ NULL,
/* 178 */ NULL,
/* 179 */ NULL,
/* 180 */ NULL,
/* 181 */ NULL,
/* 182 */ NULL,
/* 183 */ NULL,
/* 184 */ NULL,
/* 185 */ NULL,
/* 186 */ NULL,
/* 187 */ NULL,
/* 188 */ NULL,
/* 189 */ NULL,
/* 190 */ NULL,
/* 191 */ NULL,
/* 192 */ NULL,
/* 193 */ NULL,
/* 194 */ NULL,
/* 195 */ NULL,
/* 196 */ NULL,
/* 197 */ NULL,
/* 198 */ NULL,
/* 199 */ NULL,
/* 200    RPL_TRACELINK */       "Link %s%s %s %s",
/* 201    RPL_TRACECONNECTING */ "Attempt %s %s",
/* 202    RPL_TRACEHANDSHAKE */  "Handshaking %s %s",
/* 203    RPL_TRACEUNKNOWN */    "???? %s %s",
/* 204    RPL_TRACEOPERATOR */   "Operator %s %s [%s] %ld",
/* 205    RPL_TRACEUSER */       "User %s %s [%s] %ld",
/* 206    RPL_TRACESERVER */     "Server %s %dS %dC %s %s!%s@%s %ld",
/* 207    RPL_TRACESERVICE */    "Service %s %s",
/* 208    RPL_TRACENEWTYPE */    "%s 0 %s",
/* 209    RPL_TRACECLASS */      "Class %s %d",
/* 210    RPL_STATSHELP */       ":%s",
/* 211 */ NULL, /* Used */
#ifdef DEBUGMODE
/* 212    RPL_STATSCOMMANDS */ "%s %u %lu %lu %lu %lu %lu",
#else
/* 212    RPL_STATSCOMMANDS */ "%s %u %lu",
#endif
/* 213    RPL_STATSCLINE */ "%c %s * %s %d %d %s",
/* 214    RPL_STATSOLDNLINE */ "%c %s * %s %d %d %s",
/* 215    RPL_STATSILINE */ "I %s %s %d %d %s %s %d",
/* 216    RPL_STATSKLINE */ "%s %s %s",
/* 217    RPL_STATSQLINE */ "%c %s %ld %ld %s :%s",
/* 218    RPL_STATSYLINE */ "Y %s %d %d %d %d %d",
/* 219    RPL_ENDOFSTATS */ "%c :End of /STATS report",
/* 220    RPL_STATSBLINE */ "%c %s %s %s %d %d",
/* 221    RPL_UMODEIS */ "%s",
/* 222    RPL_SQLINE_NICK */ "%s :%s",
/* 223    RPL_STATSGLINE */ "%c %s %li %li %s :%s",
/* 224    RPL_STATSTLINE */ "T %s %s %s",
/* 225    RPL_STATSELINE (we use 230 instead) */ NULL,
/* 226    RPL_STATSNLINE */ "n %s %s",
/* 227    RPL_STATSVLINE */ "v %s %s %s",
/* 228    RPL_STATSBANVER */ "%s %s",
/* 229    RPL_STATSSPAMF */  "%c %s %s %s %li %li %li %s %s :%s",
/* 230    RPL_STATSEXCEPTTKL */ "%s %s %li %li %s :%s",
/* 231 */ NULL, /* rfc1459 */
/* 232    RPL_RULES */ ":- %s",
/* 233 */ NULL, /* rfc1459 */
/* 234 */ NULL, /* rfc2812 */
/* 235 */ NULL, /* rfc2812 */
/* 236 */ NULL, /* ircu */
/* 237 */ NULL, /* ircu */
/* 238 */ NULL, /* ircu, ircnet */
/* 239 */ NULL, /* ircnet */
/* 240 */ NULL, /* rfc2812, austhex */
/* 241    RPL_STATSLLINE */ "%c %s * %s %d %d",
/* 242    RPL_STATSUPTIME */ ":Server Up %ld days, %ld:%02ld:%02ld",
/* 243    RPL_STATSOLINE */ "%c %s * %s %s %s",
/* 244    RPL_STATSHLINE */ "%c %s * %s %d %d",
/* 245    RPL_STATSSLINE */ "%c %s * %s %d %d",
/* 246 */ NULL, /* rfc2812 */
/* 247    RPL_STATSXLINE */ "X %s %d",
/* 248    RPL_STATSULINE */ "U %s",
/* 249    RPL_STATSDEBUG */ ":%s",
/* 250    RPL_STATSCONN */ ":Highest connection count: %d (%d clients)",
/* 251    RPL_LUSERCLIENT */ ":There are %d users and %d invisible on %d servers",
/* 252    RPL_LUSEROP */   "%d :operator(s) online",
/* 253    RPL_LUSERUNKNOWN */ "%d :unknown connection(s)",
/* 254    RPL_LUSERCHANNELS */ "%d :channels formed",
/* 255    RPL_LUSERME */    ":I have %d clients and %d servers",
/* 256    RPL_ADMINME */    ":Administrative info about %s",
/* 257    RPL_ADMINLOC1 */  ":%s",
/* 258    RPL_ADMINLOC2 */  ":%s",
/* 259    RPL_ADMINEMAIL */ ":%s",
/* 260 */  NULL,
/* 261    RPL_TRACELOG */   "File %s %d",
/* 262 */ NULL, /* rfc2812 */
/* 263    RPL_TRYAGAIN */   "%s :Flooding detected. Please wait a while and try again.",
/* 264 */ NULL,
/* 265    RPL_LOCALUSERS */ "%d %d :Current local users %d, max %d",
/* 266    RPL_GLOBALUSERS */ "%d %d :Current global users %d, max %d",
/* 267 */ NULL, /* aircd */
/* 268 */ NULL, /* aircd */
/* 269 */ NULL, /* aircd */
/* 270 */ NULL, /* ircu */
/* 271    RPL_SILELIST */ "%s",
/* 272    RPL_ENDOFSILELIST */ ":End of Silence List",
/* 273 */ NULL, /* aircd */
/* 274 */ NULL, /* ircnet */
/* 275    RPL_STATSDLINE */ "%c %s %s",
/* 276    RPL_WHOISCERTFP */ "%s :has client certificate fingerprint %s",
/* 277 */ NULL, /* hybrid */
/* 278 */ NULL, /* hybrid */
/* 279 */ NULL,
/* 280 */ NULL, /* ircu */
/* 281 */ NULL, /* ircu, hybrid */
/* 282 */ NULL, /* ircu, hybrid */
/* 283 */ NULL, /* ircu, hybrid */
/* 284 */ NULL, /* hybrid, quakenet */
/* 285 */ NULL, /* ircu, aircd, quakenet */
/* 286 */ NULL, /* aircd, quakenet */
/* 287 */ NULL, /* aircd, quakenet */
/* 288 */ NULL, /* aircd, quakenet */
/* 289 */ NULL, /* aircd, quakenet */
/* 290 */ NULL, /* aircd, quakenet */
/* 291 */ NULL, /* aircd, quakenet */
/* 292 */ NULL, /* aircd */
/* 293 */ NULL, /* aircd */
/* 294    RPL_HELPFWD */ ":Your help-request has been forwarded to Help Operators",
/* 295    RPL_HELPIGN */ ":Your address has been ignored from forwarding",
/* 296 */ NULL, /* aircd */
/* 297 */ NULL,
/* 298 */ NULL, /* Used */
/* 299 */ NULL, /* aircd */
/* 300 */ NULL, /* rfc1459 */
/* 301    RPL_AWAY */ "%s :%s",
/* 302    RPL_USERHOST */ ":%s %s %s %s %s",
/* 303    RPL_ISON */ ":",
/* 304 */ NULL, /* RPL_TEXT */
/* 305    RPL_UNAWAY */ ":You are no longer marked as being away",
/* 306    RPL_NOWAWAY */ ":You have been marked as being away",
/* 307    RPL_WHOISREGNICK */ "%s :is identified for this nick",
/* 308    RPL_RULESSTART */ ":- %s Server Rules - ",
/* 309    RPL_ENDOFRULES */ ":End of RULES command.",
/* 310    RPL_WHOISHELPOP */ "%s :is available for help.",
/* 311    RPL_WHOISUSER */ "%s %s %s * :%s",
/* 312    RPL_WHOISSERVER */ "%s %s :%s",
/* 313    RPL_WHOISOPERATOR */ "%s :is %s",
/* 314    RPL_WHOWASUSER */ "%s %s %s * :%s",
/* 315    RPL_ENDOFWHO */ "%s :End of /WHO list.",
/* 316 */ NULL, /* rfc1459 */
/* 317    RPL_WHOISIDLE */ "%s %ld %ld :seconds idle, signon time",
/* 318    RPL_ENDOFWHOIS */ "%s :End of /WHOIS list.",
/* 319    RPL_WHOISCHANNELS */ "%s :%s",
/* 320    RPL_WHOISSPECIAL */ "%s :%s",
/* 321    RPL_LISTSTART */ "Channel :Users  Name",
#ifndef LIST_SHOW_MODES
/* 322    RPL_LIST */ "%s %d :%s",
#else
/* 322    RPL_LIST */ "%s %d :%s %s",
#endif
/* 323    RPL_LISTEND */ ":End of /LIST",
/* 324    RPL_CHANNELMODEIS */ "%s %s %s",
/* 325 */ NULL, /* rfc2812 */
/* 326 */ NULL, /* Used */
/* 327 */ NULL, /* Used */
/* 328 */ NULL, /* bahamut, austhex */
/* 329    RPL_CREATIONTIME */ "%s %lu",
/* 330    RPL_WHOISLOGGEDIN */ "%s %s :is logged in as", 
/* 331    RPL_NOTOPIC */ "%s :No topic is set.",
/* 332    RPL_TOPIC */ "%s :%s",
/* 333    RPL_TOPICWHOTIME */ "%s %s %lu",
/* 334    RPL_LISTSYNTAX */ ":%s",
/* 335    RPL_WHOISBOT */ "%s :is a \2Bot\2 on %s",
/* 336    RPL_INVITELIST */ ":%s",
/* 337    RPL_ENDOFINVITELIST */ ":End of /INVITE list.",
/* 338 */ NULL, /* ircu, bahamut */
/* 339 */ NULL, /* Used */
/* 340    RPL_USERIP */ ":%s %s %s %s %s",
/* 341    RPL_INVITING */ "%s %s",
/* 342    RPL_SUMMONING */ "%s :User summoned to irc",
/* 343 */ NULL,
/* 344 */ NULL,
/* 345 */ NULL, /* gamesurge */
/* 346    RPL_INVEXLIST */ "%s %s %s %lu",
/* 347    RPL_ENDOFINVEXLIST */ "%s :End of Channel Invite List",
/* 348    RPL_EXLIST */ "%s %s %s %lu",
/* 349    RPL_ENDOFEXLIST */ "%s :End of Channel Exception List",
/* 350 */ NULL,
/* 351    RPL_VERSION */ "%s.%s %s :%s%s%s [%s=%d]",
/* 352    RPL_WHOREPLY */ "%s %s %s %s %s %s :%d %s",
/* 353    RPL_NAMREPLY */ "%s",
/* 354 */ NULL, /* ircu */
/* 355 */ NULL, /* quakenet */
/* 356 */ NULL,
/* 357 */ NULL, /* austhex */
/* 358 */ NULL, /* austhex */
/* 359 */ NULL, /* austhex */
/* 360 */ NULL,
/* 361 */ NULL, /* rfc1459 */
/* 362    RPL_CLOSING */ "%s :Closed. Status = %d",
/* 363    RPL_CLOSEEND */ "%d: Connections Closed",
/* 364    RPL_LINKS */ "%s %s :%d %s",
/* 365    RPL_ENDOFLINKS */ "%s :End of /LINKS list.",
/* 366    RPL_ENDOFNAMES */ "%s :End of /NAMES list.",
/* 367    RPL_BANLIST */ "%s %s %s %lu",
/* 368    RPL_ENDOFBANLIST  */ "%s :End of Channel Ban List",
/* 369    RPL_ENDOFWHOWAS */ "%s :End of WHOWAS",
/* 370 */ NULL,
/* 371    RPL_INFO */ ":%s",
/* 372    RPL_MOTD */ ":- %s",
/* 373    RPL_INFOSTART */ ":Server INFO",
/* 374    RPL_ENDOFINFO */ ":End of /INFO list.",
/* 375    RPL_MOTDSTART */ ":- %s Message of the Day - ",
/* 376    RPL_ENDOFMOTD */ ":End of /MOTD command.",
/* 377 */ NULL, /* aircd, austhex */
/* 378    RPL_WHOISHOST */ "%s :is connecting from %s@%s %s",
/* 379    RPL_WHOISMODES */ "%s :is using modes %s %s",
/* 380 */ NULL, /* aircd, austhex */
/* 381    RPL_YOUREOPER */ ":You are now an IRC Operator",
/* 382    RPL_REHASHING */ "%s :Rehashing",
/* 383 */ NULL, /* rfc2812 */
/* 384    RPL_MYPORTIS */ "%d :Port to local server is\r\n",
/* 385 */ NULL, /* austhex, hybrid */
/* 386    RPL_QLIST */ "%s %s",
/* 387    RPL_ENDOFQLIST */ "%s :End of Channel Owner List",
/* 388    RPL_ALIST */ "%s %s",
/* 389    RPL_ENDOFALIST */ "%s :End of Protected User List",
/* 390 */ NULL,
/* 391    RPL_TIME */ "%s :%s",
#ifdef	ENABLE_USERS
/* 392    RPL_USERSSTART */ ":UserID   Terminal  Host",
/* 393    RPL_USERS */ ":%-8s %-9s %-8s",
/* 394    RPL_ENDOFUSERS */ ":End of Users",
/* 395    RPL_NOUSERS */ ":Nobody logged in.",
#else
/* 392 */ NULL,
/* 393 */ NULL,
/* 394 */ NULL,
/* 395 */ NULL, 
#endif
/* 396    RPL_HOSTHIDDEN */ "%s :is now your displayed host",
/* 397 */ NULL,
/* 398 */ NULL,
/* 399 */ NULL,
/* 400 */ NULL, /* Used */
/* 401    ERR_NOSUCHNICK */ "%s :No such nick/channel",
/* 402    ERR_NOSUCHSERVER */ "%s :No such server",
/* 403    ERR_NOSUCHCHANNEL */ "%s :No such channel",
/* 404    ERR_CANNOTSENDTOCHAN */ "%s :%s (%s)",
/* 405    ERR_TOOMANYCHANNELS */ "%s :You have joined too many channels",
/* 406    ERR_WASNOSUCHNICK */ "%s :There was no such nickname",
/* 407    ERR_TOOMANYTARGETS */ "%s :Too many targets. The maximum is %d for %s.",
/* 408 */ NULL, /* rfc2812, bahamut */
/* 409    ERR_NOORIGIN */ ":No origin specified",
/* 410    ERR_INVALIDCAPCMD */ "%s :Invalid CAP subcommand", 
/* 411    ERR_NORECIPIENT */ ":No recipient given (%s)",
/* 412    ERR_NOTEXTTOSEND */ ":No text to send",
/* 413    ERR_NOTOPLEVEL */ "%s :No toplevel domain specified",
/* 414    ERR_WILDTOPLEVEL */ "%s :Wildcard in toplevel Domain",
/* 415 */ NULL, /* rfc2812 */
/* 416    ERR_TOOMANYMATCHES */ "%s :%s",
/* 417 */ NULL,
/* 418 */ NULL,
/* 419 */ NULL, /* aircd */
/* 420 */ NULL,
/* 421    ERR_UNKNOWNCOMMAND */ "%s :Unknown command",
/* 422    ERR_NOMOTD */ ":MOTD File is missing",
/* 423    ERR_NOADMININFO */ "%s :No administrative info available",
/* 424    ERR_FILEERROR */ ":File error doing %s on %s",
/* 425    ERR_NOOPERMOTD */ ":OPERMOTD File is missing",
/* 426 */ NULL,
/* 427 */ NULL,
/* 428 */ NULL,
/* 429 ERR_TOOMANYAWAY */ ":Too Many aways - Flood Protection activated",
/* 430 */ NULL, /* austhex */
/* 431    ERR_NONICKNAMEGIVEN */ ":No nickname given",
/* 432    ERR_ERRONEUSNICKNAME */ "%s :Nickname is unavailable: %s",
/* 433    ERR_NICKNAMEINUSE */ "%s :Nickname is already in use.",
/* 434    ERR_NORULES */ ":RULES File is missing",
/* 435 */ NULL, /* bahamut */
/* 436    ERR_NICKCOLLISION */ "%s :Nickname collision KILL",
/* 437    ERR_BANNICKCHANGE */ "%s :Cannot change nickname while banned on channel",
/* 438    ERR_NCHANGETOOFAST */ "%s :Nick change too fast. Please try again later.",
/* 439    ERR_TARGETTOOFAST */ "%s :Message target change too fast. Please wait %ld seconds",
/* 440    ERR_SERVICESDOWN */  "%s :Services are currently down. Please try again later.",
/* 441    ERR_USERNOTINCHANNEL */ "%s %s :They aren't on that channel",
/* 442    ERR_NOTONCHANNEL */ "%s :You're not on that channel",
/* 443    ERR_USERONCHANNEL */ "%s %s :is already on channel",
/* 444    ERR_NOLOGIN */ "%s :User not logged in",
/* 445    ERR_SUMMONDISABLED */ ":SUMMON has been disabled",
/* 446    ERR_USERSDISABLED */ ":USERS has been disabled",
/* 447    ERR_NONICKCHANGE */ ":Can not change nickname while on %s (+N)",
/* 448 	ERR_FORBIDDENCHANNEL */ "%s :Cannot join channel: %s",
/* 449 */ NULL, /* ircu */
/* 450 */ NULL,
/* 451    ERR_NOTREGISTERED */ ":You have not registered",
/* 452 */ NULL, /* Used */
/* 453 */ NULL, /* Used */
/* 454 */ NULL,
/* 455    ERR_HOSTILENAME */ ":Your username %s contained the invalid "
	    "character(s) %s and has been changed to %s. "
	    "Please use only the characters 0-9 a-z A-Z _ - "
	    "or . in your username. Your username is the part "
	    "before the @ in your email address.",
/* 456 */ NULL, /* hybrid */
/* 457 */ NULL, /* hybrid */
/* 458 */ NULL, /* hybrid */
/* 459    ERR_NOHIDING */ "%s :Cannot join channel (+H)",
/* 460    ERR_NOTFORHALFOPS */ ":Halfops cannot set mode %c",
/* 461    ERR_NEEDMOREPARAMS */ "%s :Not enough parameters",
/* 462    ERR_ALREADYREGISTRED */ ":You may not reregister",
/* 463    ERR_NOPERMFORHOST */ ":Your host isn't among the privileged",
/* 464    ERR_PASSWDMISMATCH */ ":Password Incorrect",
/* 465    ERR_YOUREBANNEDCREEP */	":%s",
/* 466 */ NULL, /* rfc1459 */
/* 467    ERR_KEYSET */ "%s :Channel key already set",
/* 468    ERR_ONLYSERVERSCANCHANGE */ "%s :Only servers can change that mode",
/* 469    ERR_LINKSET */ "%s :Channel link already set",
/* 470    ERR_LINKCHANNEL */ "%s %s :[Link] %s has become full, so you are automatically being transferred to the linked channel %s",
/* 471    ERR_CHANNELISFULL */ "%s :Cannot join channel (+l)",
/* 472    ERR_UNKNOWNMODE */ "%c :is unknown mode char to me",
/* 473    ERR_INVITEONLYCHAN */ "%s :Cannot join channel (+i)",
/* 474    ERR_BANNEDFROMCHAN */ "%s :Cannot join channel (+b)",
/* 475    ERR_BADCHANNELKEY */ "%s :Cannot join channel (+k)",
/* 476    ERR_BADCHANMASK */ "%s :Bad Channel Mask",
/* 477    ERR_NEEDREGGEDNICK */ "%s :You need a registered nick to join that channel.",
/* 478    ERR_BANLISTFULL */ "%s %s :Channel ban/ignore list is full",
/* 479    ERR_LINKFAIL */ "%s :Sorry, the channel has an invalid channel link set.",
/* 480    ERR_CANNOTKNOCK */ ":Cannot knock on %s (%s)",
/* 481    ERR_NOPRIVILEGES */ ":Permission Denied- You do not have the correct IRC operator privileges",
/* 482    ERR_CHANOPRIVSNEEDED */ "%s :You're not channel operator",
/* 483    ERR_CANTKILLSERVER */ ":You cant kill a server!",
/* 484    ERR_ATTACKDENY */ "%s :Cannot kick protected user %s.",
/* 485    ERR_KILLDENY */ ":Cannot kill protected user %s.",
/* 486    ERR_NONONREG */ ":You must identify to a registered nick to private message %s",
/* 487    ERR_NOTFORUSERS */ ":%s is a server only command",
/* 488 */ NULL,
/* 489    ERR_SECUREONLYCHAN */ "%s :Cannot join channel (Secure connection is required)",
/* 490    ERR_NOSWEAR */ ":%s does not accept private messages containing swearing.",
/* 491    ERR_NOOPERHOST */ ":No O-lines for your host",
/* 492    ERR_NOCTCP */ ":%s does not accept CTCPs",
/* 493 */ NULL, /* ircu */
/* 494 */ NULL, /* ircu */
/* 495 */ NULL, /* ircu */
/* 496 */ NULL, /* ircu */
/* 497 */ NULL, /* ircu */
/* 498 */ NULL, /* ircu */
/* 499    ERR_CHANOWNPRIVNEEDED */ "%s :You're not a channel owner",
/* 500    ERR_TOOMANYJOINS */ "%s :Too many join requests. Please wait a while and try again.",
/* 501    ERR_UMODEUNKNOWNFLAG */ ":Unknown MODE flag",
/* 502    ERR_USERSDONTMATCH */ ":Cant change mode for other users",
/* 503 */ NULL, /* austhex */
/* 504 */ NULL, /* Used */
/* 505 */ NULL,
/* 506 */ NULL,
/* 507 */ NULL,
/* 508 */ NULL,
/* 509 */ NULL,
/* 510 */ NULL,
/* 511    ERR_SILELISTFULL */ "%s :Your silence list is full",
/* 512    ERR_TOOMANYWATCH */ "%s :Maximum size for WATCH-list is 128 entries",
/* 513    ERR_NEEDPONG */ ":To connect, type /QUOTE PONG %lX",
/* 514    ERR_TOOMANYDCC */ "%s :Your dcc allow list is full. Maximum size is %d entries",
/* 515 */ NULL, /* ircu */
/* 516 */ NULL, /* ircu */
/* 517    ERR_DISABLED*/ "%s :%s", /* ircu */
/* 518    518 */ ":Cannot invite (+V) at channel %s",
/* 519    519 */ ":Cannot join channel %s (Admin only)",
/* 520    520 */ ":Cannot join channel %s (IRCops only)",
/* 521    ERR_LISTSYNTAX */ ":Bad list syntax, type /quote list ? or /raw list ?",
/* 522    ERR_WHOSYNTAX */ ":/WHO Syntax incorrect, use /who ? for help",
/* 523 	  ERR_WHOLIMEXCEED */ ":Error, /who limit of %d exceeded. Please narrow your search down and try again",
/* 524    ERR_OPERSPVERIFY */ ":Trying to join +s or +p channel as an oper. Please invite yourself first.",
/* 525 */ NULL, /* draft-brocklesby-irc-usercmdpfx */
/* 526 */ NULL, /* draft-brocklesby-irc-usercmdpfx */
/* 527 */ NULL,
/* 528 */ NULL,
/* 529 */ NULL,
/* 530 */ NULL,
/* 531    ERR_CANTSENDTOUSER */ "%s :%s",
/* 532 */ NULL,
/* 533 */ NULL,
/* 534 */ NULL,
/* 535 */ NULL,
/* 536 */ NULL,
/* 537 */ NULL,
/* 538 */ NULL,
/* 539 */ NULL,
/* 540 */ NULL,
/* 541 */ NULL,
/* 542 */ NULL,
/* 543 */ NULL,
/* 544 */ NULL,
/* 545 */ NULL,
/* 546 */ NULL,
/* 547 */ NULL,
/* 548 */ NULL,
/* 549 */ NULL,
/* 550 */ NULL, /* quakenet */
/* 551 */ NULL, /* quakenet */
/* 552 */ NULL, /* quakenet */
/* 553 */ NULL, /* quakenet */
/* 554 */ NULL,
/* 555 */ NULL,
/* 556 */ NULL,
/* 557 */ NULL,
/* 558 */ NULL,
/* 559 */ NULL,
/* 560 */ NULL,
/* 561 */ NULL,
/* 562 */ NULL,
/* 563 */ NULL,
/* 564 */ NULL,
/* 565 */ NULL,
/* 566 */ NULL,
/* 567 */ NULL,
/* 568 */ NULL,
/* 569 */ NULL,
/* 570 */ NULL,
/* 571 */ NULL,
/* 572 */ NULL,
/* 573 */ NULL,
/* 574 */ NULL,
/* 575 */ NULL,
/* 576 */ NULL,
/* 577 */ NULL,
/* 578 */ NULL,
/* 579 */ NULL,
/* 580 */ NULL,
/* 581 */ NULL,
/* 582 */ NULL,
/* 583 */ NULL,
/* 584 */ NULL,
/* 585 */ NULL,
/* 586 */ NULL,
/* 587 */ NULL,
/* 588 */ NULL,
/* 589 */ NULL,
/* 590 */ NULL,
/* 591 */ NULL,
/* 592 */ NULL,
/* 593 */ NULL,
/* 594 */ NULL,
/* 595 */ NULL,
/* 596 */ NULL,
/* 597    RPL_REAWAY */ "%s %s %s %d :%s",
/* 598    RPL_GONEAWAY */ "%s %s %s %d :%s",
/* 599    RPL_NOTAWAY */ "%s %s %s %d :is no longer away",
/* 600    RPL_LOGON */ "%s %s %s %d :logged online",
/* 601    RPL_LOGOFF */ "%s %s %s %d :logged offline",
/* 602    RPL_WATCHOFF */ "%s %s %s %d :stopped watching",
/* 603    RPL_WATCHSTAT */ ":You have %d and are on %d WATCH entries",
/* 604    RPL_NOWON */ "%s %s %s %ld :is online",
/* 605    RPL_NOWOFF */ "%s %s %s %ld :is offline",
/* 606    RPL_WATCHLIST */ ":%s",
/* 607    RPL_ENDOFWATCHLIST */ ":End of WATCH %c",
/* 608    RPL_CLEARWATCH */ ":Your WATCH list is now empty",
/* 609    RPL_NOWISAWAY */ "%s %s %s %ld :is away",
/* 610    RPL_MAPMORE */ ":%s%-*s --> *more*",
/* 611 */ NULL, /* ultimate */
/* 612 */ NULL, /* ultimate */
/* 613 */ NULL, /* ultimate */
/* 614 */ NULL,
/* 615 */ NULL, /* ptlink, ultimate */
/* 616 */ NULL, /* ultimate */
/* 617    RPL_DCCSTATUS */ ":%s has been %s your DCC allow list",
/* 618    RPL_DCCLIST */ ":%s",
/* 619    RPL_ENDOFDCCLIST */ ":End of DCCALLOW %s",
/* 620    RPL_DCCINFO */ ":%s",
/* 621 */ NULL, /* ultimate */
/* 622 */ NULL, /* ultimate */
/* 623 */ NULL, /* ultimate */
/* 624 */ NULL, /* ultimate */
/* 625 */ NULL, /* ultimate */
/* 626 */ NULL, /* ultimate */
/* 627 */ NULL,
/* 628 */ NULL,
/* 629 */ NULL,
/* 630 */ NULL, /* ultimate */
/* 631 */ NULL, /* ultimate */
/* 632 */ NULL,
/* 633 */ NULL,
/* 634 */ NULL,
/* 635 */ NULL,
/* 636 */ NULL,
/* 637 */ NULL,
/* 638 */ NULL,
/* 639 */ NULL,
/* 640 */ NULL,
/* 641 */ NULL,
/* 642 */ NULL,
/* 643 */ NULL,
/* 644 */ NULL,
/* 645 */ NULL,
/* 646 */ NULL,
/* 647 */ NULL,
/* 648 */ NULL,
/* 649 */ NULL,
/* 650 */ NULL,
/* 651 */ NULL,
/* 652 */ NULL,
/* 653 */ NULL,
/* 654 */ NULL,
/* 655 */ NULL,
/* 656 */ NULL,
/* 657 */ NULL,
/* 658 */ NULL,
/* 659 RPL_SPAMCMDFWD */ "%s :Command processed, but a copy has been sent to ircops for evaluation (anti-spam) purposes. [%s]",
/* 660 */ NULL, /* kineircd */
/* 661 */ NULL, /* kineircd */
/* 662 */ NULL, /* kineircd */
/* 663 */ NULL, /* kineircd */
/* 664 */ NULL, /* kineircd */
/* 665 */ NULL, /* kineircd */
/* 666 */ NULL, /* kineircd */
/* 667 */ NULL,
/* 668 */ NULL,
/* 669 */ NULL,
/* 670 RPL_STARTTLS */ ":STARTTLS successful, go ahead with TLS handshake", /* kineircd */
/* 671 RPL_WHOISSECURE */ "%s :%s", /* our variation on the kineircd numeric */
/* 672 */ NULL, /* ithildin */
/* 673 */ NULL, /* ithildin */
/* 674 */ NULL,
/* 675 */ NULL,
/* 676 */ NULL,
/* 677 */ NULL,
/* 678 */ NULL, /* kineircd */
/* 679 */ NULL, /* kineircd */
/* 680 */ NULL,
/* 681 */ NULL,
/* 682 */ NULL, /* kineircd */
/* 683 */ NULL,
/* 684 */ NULL,
/* 685 */ NULL,
/* 686 */ NULL,
/* 687 */ NULL, /* kineircd */
/* 688 */ NULL, /* kineircd */
/* 689 */ NULL, /* kineircd */
/* 690 */ NULL, /* kineircd */
/* 691 ERR_STARTTLS */ ":%s",
/* 692 */ NULL,
/* 693 */ NULL,
/* 694 */ NULL,
/* 695 */ NULL,
/* 696 */ NULL,
/* 697 */ NULL,
/* 698 */ NULL,
/* 699 */ NULL,
/* 700 */ NULL,
/* 701 */ NULL,
/* 702 */ NULL,
/* 703 */ NULL,
/* 704 */ NULL,
/* 705 */ NULL,
/* 706 */ NULL,
/* 707 */ NULL,
/* 708 */ NULL,
/* 709 */ NULL,
/* 710 */ NULL,
/* 711 */ NULL,
/* 712 */ NULL,
/* 713 */ NULL,
/* 714 */ NULL,
/* 715 */ NULL,
/* 716 */ NULL, /* ratbox */
/* 717 */ NULL, /* ratbox */
/* 718 */ NULL, /* ratbox */
/* 719 */ NULL,
/* 720 */ NULL,
/* 721 */ NULL,
/* 722 */ NULL,
/* 723 */ NULL,
/* 724 */ NULL,
/* 725 */ NULL,
/* 726 */ NULL,
/* 727 */ NULL,
/* 728 */ NULL,
/* 729 */ NULL,
/* 730 */ NULL,
/* 731 */ NULL,
/* 732 */ NULL,
/* 733 */ NULL,
/* 734 */ NULL,
/* 735 */ NULL,
/* 736 */ NULL,
/* 737 */ NULL,
/* 738 */ NULL,
/* 739 */ NULL,
/* 740 */ NULL,
/* 741 */ NULL,
/* 742 ERR_MLOCKRESTRICTED */ "%s %c %s :MODE cannot be set due to channel having an active MLOCK restriction policy",
/* 743 */ NULL,
/* 744 */ NULL,
/* 745 */ NULL,
/* 746 */ NULL,
/* 747 */ NULL,
/* 748 */ NULL,
/* 749 */ NULL,
/* 750 */ NULL,
/* 751 */ NULL,
/* 752 */ NULL,
/* 753 */ NULL,
/* 754 */ NULL,
/* 755 */ NULL,
/* 756 */ NULL,
/* 757 */ NULL,
/* 758 */ NULL,
/* 759 */ NULL,
/* 760 */ NULL,
/* 761 */ NULL,
/* 762 */ NULL,
/* 763 */ NULL,
/* 764 */ NULL,
/* 765 */ NULL,
/* 766 */ NULL,
/* 767 */ NULL,
/* 768 */ NULL,
/* 769 */ NULL,
/* 770 */ NULL,
/* 771 */ NULL, /* ithildin */
/* 772 */ NULL,
/* 773 */ NULL, /* ithildin */
/* 774 */ NULL, /* ithildin */
/* 775 */ NULL,
/* 776 */ NULL,
/* 777 */ NULL,
/* 778 */ NULL,
/* 779 */ NULL,
/* 780 */ NULL,
/* 781 */ NULL,
/* 782 */ NULL,
/* 783 */ NULL,
/* 784 */ NULL,
/* 785 */ NULL,
/* 786 */ NULL,
/* 787 */ NULL,
/* 788 */ NULL,
/* 789 */ NULL,
/* 790 */ NULL,
/* 791 */ NULL,
/* 792 */ NULL,
/* 793 */ NULL,
/* 794 */ NULL,
/* 795 */ NULL,
/* 796 */ NULL,
/* 797 */ NULL,
/* 798 */ NULL,
/* 799 */ NULL,
/* 800 */ NULL,
/* 801 */ NULL,
/* 802 */ NULL,
/* 803 */ NULL,
/* 804 */ NULL,
/* 805 */ NULL,
/* 806 */ NULL,
/* 807 */ NULL,
/* 808 */ NULL,
/* 809 */ NULL,
/* 810 */ NULL,
/* 811 */ NULL,
/* 812 */ NULL,
/* 813 */ NULL,
/* 814 */ NULL,
/* 815 */ NULL,
/* 816 */ NULL,
/* 817 */ NULL,
/* 818 */ NULL,
/* 819 */ NULL,
/* 820 */ NULL,
/* 821 */ NULL,
/* 822 */ NULL,
/* 823 */ NULL,
/* 824 */ NULL,
/* 825 */ NULL,
/* 826 */ NULL,
/* 827 */ NULL,
/* 828 */ NULL,
/* 829 */ NULL,
/* 830 */ NULL,
/* 831 */ NULL,
/* 832 */ NULL,
/* 833 */ NULL,
/* 834 */ NULL,
/* 835 */ NULL,
/* 836 */ NULL,
/* 837 */ NULL,
/* 838 */ NULL,
/* 839 */ NULL,
/* 840 */ NULL,
/* 841 */ NULL,
/* 842 */ NULL,
/* 843 */ NULL,
/* 844 */ NULL,
/* 845 */ NULL,
/* 846 */ NULL,
/* 847 */ NULL,
/* 848 */ NULL,
/* 849 */ NULL,
/* 850 */ NULL,
/* 851 */ NULL,
/* 852 */ NULL,
/* 853 */ NULL,
/* 854 */ NULL,
/* 855 */ NULL,
/* 856 */ NULL,
/* 857 */ NULL,
/* 858 */ NULL,
/* 859 */ NULL,
/* 860 */ NULL,
/* 861 */ NULL,
/* 862 */ NULL,
/* 863 */ NULL,
/* 864 */ NULL,
/* 865 */ NULL,
/* 866 */ NULL,
/* 867 */ NULL,
/* 868 */ NULL,
/* 869 */ NULL,
/* 870 */ NULL,
/* 871 */ NULL,
/* 872 */ NULL,
/* 873 */ NULL,
/* 874 */ NULL,
/* 875 */ NULL,
/* 876 */ NULL,
/* 877 */ NULL,
/* 878 */ NULL,
/* 879 */ NULL,
/* 880 */ NULL,
/* 881 */ NULL,
/* 882 */ NULL,
/* 883 */ NULL,
/* 884 */ NULL,
/* 885 */ NULL,
/* 886 */ NULL,
/* 887 */ NULL,
/* 888 */ NULL,
/* 889 */ NULL,
/* 890 */ NULL,
/* 891 */ NULL,
/* 892 */ NULL,
/* 893 */ NULL,
/* 894 */ NULL,
/* 895 */ NULL,
/* 896 */ NULL,
/* 897 */ NULL,
/* 898 */ NULL,
/* 899 */ NULL,
/* 900 RPL_LOGGEDIN */          "%s!%s@%s %s :You are now logged in as %s.",
/* 901 RPL_LOGGEDOUT */         "%s!%s@%s :You are now logged out.",
/* 902 ERR_NICKLOCKED */        ":You must use a nick assigned to you.",
/* 903 RPL_SASLSUCCESS */       ":SASL authentication successful",
/* 904 ERR_SASLFAIL */          ":SASL authentication failed",
/* 905 ERR_SASLTOOLONG */       ":SASL message too long",
/* 906 ERR_SASLABORTED */       ":SASL authentication aborted",
/* 907 ERR_SASLALREADY */       ":You have already completed SASL authentication",
/* 908 RPL_SASLMECHS */         "%s :are available SASL mechanisms",
/* 909 */ NULL,
/* 910 */ NULL,
/* 911 */ NULL,
/* 912 */ NULL,
/* 913 */ NULL,
/* 914 */ NULL,
/* 915 */ NULL,
/* 916 */ NULL,
/* 917 */ NULL,
/* 918 */ NULL,
/* 919 */ NULL,
/* 920 */ NULL,
/* 921 */ NULL,
/* 922 */ NULL,
/* 923 */ NULL,
/* 924 */ NULL,
/* 925 */ NULL,
/* 926 */ NULL,
/* 927 */ NULL,
/* 928 */ NULL,
/* 929 */ NULL,
/* 930 */ NULL,
/* 931 */ NULL,
/* 932 */ NULL,
/* 933 */ NULL,
/* 934 */ NULL,
/* 935 */ NULL,
/* 936 */ NULL,
/* 937 */ NULL,
/* 938 */ NULL,
/* 939 */ NULL,
/* 940 */ NULL,
/* 941 */ NULL,
/* 942 */ NULL,
/* 943 */ NULL,
/* 944 */ NULL,
/* 945 */ NULL,
/* 946 */ NULL,
/* 947 */ NULL,
/* 948 */ NULL,
/* 949 */ NULL,
/* 950 */ NULL,
/* 951 */ NULL,
/* 952 */ NULL,
/* 953 */ NULL,
/* 954 */ NULL,
/* 955 */ NULL,
/* 956 */ NULL,
/* 957 */ NULL,
/* 958 */ NULL,
/* 959 */ NULL,
/* 960 */ NULL,
/* 961 */ NULL,
/* 962 */ NULL,
/* 963 */ NULL,
/* 964 */ NULL,
/* 965 */ NULL,
/* 966 */ NULL,
/* 967 */ NULL,
/* 968 */ NULL,
/* 969 */ NULL,
/* 970 */ NULL,
/* 971 */ NULL,
/* 972 ERR_CANNOTDOCOMMAND */ "%s :%s",
/* 973 */ NULL, /* kineircd */
/* 974 ERR_CANNOTCHANGECHANMODE */ "%c :%s",
/* 975 */ NULL, /* kineircd */
/* 976 */ NULL, /* kineircd */
/* 977 */ NULL, /* kineircd */
/* 978 */ NULL, /* kineircd */
/* 979 */ NULL, /* kineircd */
/* 980 */ NULL, /* kineircd */
/* 981 */ NULL, /* kineircd */
/* 982 */ NULL, /* kineircd */
/* 983 */ NULL, /* kineircd */
/* 984 */ NULL,
/* 985 */ NULL,
/* 986 */ NULL,
/* 987 */ NULL,
/* 988 */ NULL,
/* 989 */ NULL,
/* 990 */ NULL,
/* 991 */ NULL,
/* 992 */ NULL,
/* 993 */ NULL,
/* 994 */ NULL,
/* 995 */ NULL,
/* 996 */ NULL,
/* 997 */ NULL,
/* 998 */ NULL,
/* 999    ERR_NUMERICERR */ "Numeric error!",
/* 1000 */ NULL,
};

char *getreply(int numeric)
{
	if ((numeric < 0) || (numeric > 999) || !replies[numeric])
		return replies[ERR_NUMERICERR];
	else
		return replies[numeric];
}

#if defined _skwl_dccmd_included
  #endinput
#endif
#define _skwl_dccmd_included

#include <discord-connector>
#include <YSI_Coding\y_va>

// Macros
#define SendDC  DCC_SendChannelMessage
#define DCMD    SKWLCMD
#define DC_CMD  SKWLCMD
#define SKWLCMD:%0(%1,%2)          \
            forward skwl_cmd_%0(%1,%2[]); \
            public skwl_cmd_%0(%1,%2[])

forward OnDCCommandPerformed(args[], success);

new DCC_Channel:SKWL_Discord_Channel;

public DCC_OnMessageCreate(DCC_Message:message){
    new realMsg[100];
    new bool:IsBot;
    new DCC_User:author;

    DCC_GetMessageContent(message, realMsg, 100);
    DCC_GetMessageChannel(message, SKWL_Discord_Channel);
    DCC_GetMessageAuthor(message, author);
    DCC_IsUserBot(author, IsBot);
    
    if(!IsBot){
        new dmsg[10][128];
        new command[16], args[50];

        explode(dmsg, realMsg, " ", 2);

        sscanf(realMsg, "s[16]s[50]", command, args);
        if(strfind(command, SKWL_PREFIX, true) == 0){
            new funcdc[128];
            strdel(command, 0, 1);
            format(funcdc, sizeof(funcdc), "skwl_cmd_%s", command);

            if(isnull(dmsg[1])) {
                CallLocalFunction("OnDCCommandPerformed", "si", realMsg, CallLocalFunction(funcdc, "is", _: author, "\1"));
            }
            else{
                CallLocalFunction("OnDCCommandPerformed", "si", realMsg, CallLocalFunction(funcdc, "is", _: author, args));
            }
        }
    }
    return 1;
}

explode(aExplode[][], const sSource[], const sDelimiter[] = " ", iVertices = sizeof aExplode, iLength = sizeof aExplode[]){
    new iNode, iPointer, iPrevious = -1, iDelimiter = strlen(sDelimiter);

    while(iNode < iVertices){
        iPointer = strfind(sSource, sDelimiter, false, iPointer);
        if(iPointer == -1){
            strmid(aExplode[iNode], sSource, iPrevious, strlen(sSource), iLength);
            break;
        }
        else{
            strmid(aExplode[iNode], sSource, iPrevious, iPointer, iLength);
        }
        iPrevious = (iPointer += iDelimiter);
        ++iNode;
    }
    return iPrevious;
}

stock GetDiscordName(DCC_User:user)
{
	new pname_[32];
	DCC_GetUserName(user, pname_);
	return pname_;
}

stock UserHasRole(DCC_User:user, DCC_Role:role)
{
	new bool:value;
	new DCC_Guild:jGuild = DCC_FindGuildById(GUILD_ID);
	DCC_HasGuildMemberRole(jGuild, user, role, value);
	return value;
}

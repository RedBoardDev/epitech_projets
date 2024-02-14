Contributors:
-------
    `oscar.frank@epitech.eu`
    `thomas.ott@epitech.eu`
    `luca.haumesser@epitech.eu`

Protocol:
-------
    WELCOME ⭲ 101

    GOODBYE ⭲ 102

    /HELP
        - /help : show help
            ⭸ help showed ⭲ 100
                300 ⭰ help failed

    /CONNECTION
        /LOGIN
            - /login [“user_name”] : set the user_name used by client
                ⭸ user_name successed ⭲ 110
                    310 ⭰ user_name failed

        /LOGOUT
            - /logout : disconnect the client from the server
                ⭸ disconnect the client from the server successed ⭲ 111
                    311 ⭰ disconnect the client from the server failed

    /CONTRIBUTORS
        /USERS
            - /users : get the list of all users that exist on the domain
                ⭸ list of all users that exist on the domain started ⭲ 120
                    ⭸ list of all users that exist on the domain successed ⭲ 220
                    320 ⭰ list of all users that exist on the domain failed

        /USER
            - /user [“user_uuid”] : get details about the requested user
                ⭸ get details about the requested user successed ⭲ 121
                    321 ⭰ get details about the requested user failed

    /ACTIONS
        /SEND
            - /send [“user_uuid”] [“message_body”] : send a message to specific user
                ⭸ send a message to specific user successed ⭲ 130
                    330 ⭰ send a message to specific user failed

        /MESSAGES
            - /messages [“user_uuid”] : list all messages exchanged with the specified user
                ⭸ list all messages exchanged with the specified user started ⭲ 131
                    ⭸ list all messages exchanged with the specified user successed ⭲ 231
                    331 ⭰ list all messages exchanged with the specified user failed

        /SUBSCRIBE
            - /subscribe [“team_uuid”] : subscribe to the events of a team and its sub directories (enable reception of all events from a team)
                ⭸ subscribe to the events of a team and its sub directories successed ⭲ 132
                    332 ⭰ subscribe to the events of a team and its sub directories failed

        /SUBSCRIBED
            - /subscribed ?[“team_uuid”] : list all subscribed teams or list all users subscribed to a team
                ⭸ list all subscribed teams or list all users subscribed to a team started ⭲ 133
                    ⭸ list all subscribed teams or list all users subscribed to a team successed ⭲ 233
                    333 ⭰ list all subscribed teams or list all users subscribed to a team failed

        /UNSUBSCRIBE
            - /unsubscribe [“team_uuid”] : unsubscribe from a team
                ⭸ unsubscribe from a team successed ⭲ 134
                    334 ⭰ unsubscribe from a team failed

    /USE
        - /use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”] : Sets the command context to a team/channel/thread
            ⭸ Sets the command context to a team/channel/thread successed ⭲ 140
                340 ⭰ Sets the command context to a team/channel/thread failed

    /CREATE
        - /create [“team_name”] [“team_description”] : create a new team
            ⭸ team created ⭲ 150

        - /create [“channel_name”] [“channel_description”] : create a new channel
            ⭸ channel created ⭲ 151

        - /create [“thread_title”] [“thread_message”] : create a new thread
            ⭸ thread created ⭲ 152

        - /create [“comment_body”] : create a new reply
            ⭸ reply created ⭲ 153

        355 ⭰ reply failed

    /LIST
        - /list : list all existing teams
            ⭸ list all teams started ⭲ 160
                ⭸ list all teams successed ⭲ 260

        - /list : list all existing channels
            ⭸ list all channels started ⭲ 161
                ⭸ list all channels successed ⭲ 261

        - /list : list all existing threads
            ⭸ list all threads started ⭲ 162
                ⭸ list all threads successed ⭲ 262

        - /list : list all existing replies
            ⭸ list all replies started ⭲ 163

        365 ⭰ list failed

    /INFO
        - /info : display currently logged-in user details
            ⭸ currently logged-in user details displayed ⭲ 170

        - /info : display currently selected team details
            ⭸ currently selected team details displayed ⭲ 171

        - /info : display currently selected channel details
            ⭸ currently selected channel details displayed ⭲ 172

        - /info : display currently selected thread details
            ⭸ currently selected thread details displayed ⭲ 173

        375 ⭰ info failed

    EVENT
        - event login ⭲ 990
        - event logout ⭲ 991
        - event team created ⭲ 992
        - event channel created ⭲ 993
        - event thread created ⭲ 994
        - event reply created ⭲ 995

#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <vector>
#include <thread>
#include "Entities/Entity.hpp"
#include "Entities/Player.hpp"
#include "Entities/Monsters/Little.hpp"
#include "Entities/Monsters/Zigzager.hpp"
#include "Entities/Monsters/Follower.hpp"
#include "Entities/Monsters/BurstFire.hpp"
#include "Entities/Monsters/Boss1.hpp"
#include "Entities/Monsters/Boss2.hpp"
#include "Entities/Monsters/Boss3.hpp"
#include "Entities/Monsters/Boss4.hpp"
#include "Entities/Monsters/Boss5.hpp"
#include "Entities/Monsters/Boss6.hpp"
#include "Entities/Monsters/Boss7.hpp"
#include "Entities/Monsters/Boss8.hpp"
#include "../Client.hpp"
#include "Levels.hpp"
#include "Entities/Bonus/Bonus.hpp"

class Room
{
    public:
        class ChatMessage {
            public: 
                /**
                 * @brief Construct a new Chat Message object
                 * 
                 * @param room The room the message is sent in
                 * @param playerId The id of the player that sent the message
                 * @param message The message
                 */
                ChatMessage(Room &room, u_int playerId, const std::string &message);
                ~ChatMessage();
                ChatMessage(const ChatMessage &chatMessage) = delete;
                ChatMessage(ChatMessage &&chatMessage) = delete;
                ChatMessage &operator=(const ChatMessage &chatMessage) = delete;
                ChatMessage &operator=(ChatMessage &&chatMessage) = delete;

                /**
                 * @brief Get the Time Stamp object
                 * 
                 * @return const std::chrono::system_clock::time_point& 
                 */
                const std::chrono::system_clock::time_point &getTimeStamp() const;

                /**
                 * @brief Get the Player Id object
                 * 
                 * @return u_int 
                 */
                u_int getPlayerId() const;

                /**
                 * @brief Get the Message object
                 * 
                 * @return const std::string& 
                 */
                const std::string &getMessage() const;

            private:
                std::chrono::system_clock::time_point _timeStamp;
                u_int _playerId;
                std::string _message;
        };

        enum State {
            WAIT = 0,
            RUN = 1,
            END = 2,
            STOPPED = 3
        };

    private:
        State _state;
        std::thread _thread;
        
        std::vector<std::unique_ptr<Player>> _players;
        std::vector<std::unique_ptr<Monster>> _monsters;
        const std::vector<std::shared_ptr<Client>> &_allClients;
        u_int _id;
        unsigned int _maxPlayer;
        unsigned int _progress;
        u_int _playersIds;
        bool _private;
        Levels _levels;

        u_int _missilesIds;
        u_int _monstersIds;

        size_t _lastMapRefresh;
        size_t _lastWaitMessage;
        size_t _lastJoin;
        size_t _lastMissileUpdate;
        size_t _lastPlayerUpdate;
        size_t _lastGameOver;

        std::unique_ptr<BonusBox> _bonusBox;
        size_t _lastBonusBoxSpawn;
        size_t _bonusIds = 0;

        size_t _bombIds = 0;
        size_t _laserIds = 0;
        size_t _rayIds = 0;
        std::vector<std::unique_ptr<ChatMessage>> _chatMessages;

        void refresh();
        void update();
        void startGame();
        void checkCollisionPlayer();
        void checkCollisionMonsters();
        void handleBonus();
        void checkCollisionBonus();
        void handleForcePod();

    public:
        /**
         * @brief Construct a new Room object
         *
         * @param id The id of the room
         * @param client The client that created the room
         * @param privateRoom If the room is private or not (default: false)
         */
        Room(u_int id, std::shared_ptr<Client> client, Levels &levels, const std::vector<std::shared_ptr<Client>> &allClients, bool privateRoom = false);
        ~Room();
        Room(const Room &room) = delete;
        Room(Room &&room) = delete;
        Room &operator=(const Room &room) = delete;
        Room &operator=(Room &&room) = delete;
        /**
         * @brief Get the state of the room (WAIT | RUN | END | STOPPED)
         *
         * @return State
         */
        State getState() const;
        /**
         * @brief Get the id of the room
         *
         * @return u_int
         */
        u_int getId() const;
        /**
         * @brief Get the number of players in the room
         *
         * @return unsigned int
         */
        unsigned int getNbPlayer() const;
        /**
         * @brief Get the progress of the game
         *
         * @return unsigned int
         */
        unsigned int getProgress() const;
        /**
         * @brief Get max number of players allowed in the room
         *
         * @return unsigned int
         */
        unsigned int getMaxPlayer() const;
        /**
         * @brief Add a new player to the room
         *
         * @param client The client that wants to join the room
         */
        void addPlayer(std::shared_ptr<Client> client);

        /**
         * @brief remove a player from the room
         * 
         * @param client client object linked to the player
         */
       
        void removePlayer(std::shared_ptr<Client> client);
         /**
         * @brief Move a player in the room
         *
         * @param client The client that wants to move
         * @param move The move to make (PLAYER_MOVE_UP | PLAYER_MOVE_DOWN | PLAYER_MOVE_LEFT | PLAYER_MOVE_RIGHT) you can combine them with the | binary operator
         * @param nbr The number of move to make (default: 1)
         */
        void movePlayer(std::shared_ptr<Client> client, char move, char nbr = 1);
        /**
         * @brief Checks if a client is in the room
         *
         * @param client The client to check
         * @return true If the client is in the room
         * @return false If the client is not in the room
         */
        bool isClientInRoom(std::shared_ptr<Client> client);
        /**
         * @brief Get the player associated with a client
         *
         * @param client The client to find
         * @return Player&
         */
        Player &getPlayer(std::shared_ptr<Client> client);
        /**
         * @brief Send a packet to all players in the room
         *
         * @param stream The packet to send
         */
        void sendToAll(const Stream &stream);

        /**
         * @brief Get the id of the next missile to create
         *
         * @return u_int&
         */
        u_int &getMissilesIds();

        /**
         * @brief Add a monster in the room
         * 
         * @param type The type of the monster to add
         * @param x The x position of the monster
         * @param y The y position of the monster
         *
         */
        void addMonster(IEntity::Type type, int x, int y);

        /**
         * @brief Get the position of the nearest player from an entity
         * 
         * @param entity The entity to check
         *
         * @return std::pair<short, short> The position of the nearest player
         */
        std::pair<short, short> getNearestPlayerPos(const IEntity &entity);

        /**
         * @brief Check if the room is private
         * 
         * @return true if the room is private
         * @return false if the room is not private
         */
        bool isPrivate() const;

        /**
         * @brief Check if the it remain monsters in the room
         * 
         * @return true if there is still monsters
         * @return false if there is no more monsters
         */
        bool isMonster() const;

        /**
         * @brief Get the id of the next Bomb to create
         * 
         * @return size_t& 
         */
        size_t &getBombIds();

        /**
         * @brief Get the id of the next Laser to create
         * 
         * @return size_t& 
         */
        size_t &getLaserIds();

        /**
         * @brief Get the id of the next Ray to create
         * 
         * @return size_t& 
         */
        size_t &getRayIds();


        /**
         * @brief Apply damage to all monsters in a zone
         * 
         * @param x the x position of the center of the zone
         * @param y the y position of the center of the zone
         * @param radius the radius of the zone
         * @param player the player from which the damage comes
         */
        void degInZone(float x, float y, size_t radius, Player &player);

        /**
         * @brief Get the Players object
         * 
         * @return std::vector<std::unique_ptr<Player>>& 
         */
        std::vector<std::unique_ptr<Player>> &getPlayers();

        /**
         * @brief The mutex that lock the players vector
         * 
         */
        std::mutex _playersMutex;

        /**
         * @brief Send a message in the chat
         * 
         * @param client The client that send the message
         * @param message The message to send
         */
        void sendChat(std::shared_ptr<Client> client, const std::string &message);
};


#endif

#include "Missile.hpp"
#include "../Room.hpp"

Missile::Missile(Room &room, Missile::Type type, u_int id, short x, short y, short vx, short vy):
    AEntity(room, id, x, y, (type == Missile::Type::FIRE_BALL ? FIRE_BALL_WIDTH : MISSILE_WIDTH)
    || (type == Missile::Type::BOSS8_MISSILE ? BOSS8_MISSILE_WIDTH : MISSILE_WIDTH), (type == Missile::Type::FIRE_BALL ? FIRE_BALL_HEIGHT : MISSILE_HEIGHT)
    || (type == Missile::Type::BOSS8_MISSILE ? BOSS8_MISSILE_HEIGHT : MISSILE_HEIGHT)),
    _type(type),
    _vx(vx),
    _vy(vy)
{}

Missile::Missile(Room &room, Missile::Type type, u_int id, const std::pair<short, short> &pos, const std::pair<short, short> &velocity):
    AEntity(room, id, pos, {(type == Missile::Type::FIRE_BALL ? FIRE_BALL_WIDTH : MISSILE_WIDTH)
    || (type == Missile::Type::BOSS8_MISSILE ? BOSS8_MISSILE_WIDTH : MISSILE_WIDTH), (type == Missile::Type::FIRE_BALL ? FIRE_BALL_HEIGHT : MISSILE_HEIGHT)
    || (type == Missile::Type::BOSS8_MISSILE ? BOSS8_MISSILE_HEIGHT : MISSILE_HEIGHT)}),
    _type(type),
    _vx(velocity.first),
    _vy(velocity.second)
{}

Missile::~Missile()
{
    _room.sendToAll(StreamFactory::missileDestroyed(_id, _type, _box.x, _box.y));
}

void Missile::refresh()
{
    auto now = std::chrono::system_clock::now();

    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - _lastMove).count() >= MISSILES_MOVE_TIME) {
        move(_vx, _vy);
        _room.sendToAll(StreamFactory::missilePos(_id, _type, _box.x, _box.y));
        _lastMove = now;
    }
}

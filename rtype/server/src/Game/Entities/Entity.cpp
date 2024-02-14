#include "Entity.hpp"
#include "../Room.hpp"

AEntity::AEntity(Room &room, u_int id, short x, short y, short w, short h):
    _room(room),
    _id(id),
    _box(x, y, w, h),
    _lastMove(std::chrono::system_clock::now())
{
    _exist = true;
    _deletable = false;
    _life = 100;
}

AEntity::AEntity(Room &room, u_int id, const std::pair<short, short> &pos, const std::pair<short, short> &size):
    _room(room),
    _id(id),
    _box(pos, size),
    _lastMove(std::chrono::system_clock::now())
{
    _exist = true;
    _deletable = false;
    _life = 100;
}

std::pair<short, short> AEntity::position() const
{
    return {_box.x, _box.y};
}

u_int AEntity::id() const
{
    return _id;
}

bool AEntity::isOutOfScreen() const
{
    if (IEntity::Type::ZIGZAGER_MONSTER)
        return _box.x < 0 - _box.width || _box.x > SCREEN_WIDTH || _box.y < -500  - _box.height || _box.y > SCREEN_HEIGHT + 500;
    return _box.x < 0 - _box.width || _box.x > SCREEN_WIDTH || _box.y < 0 - _box.height || _box.y > SCREEN_HEIGHT;

}

bool AEntity::collide(const IEntity &other)
{
    if (_exist && other.exists())
        return _box.collide(other.box());
    return false;
}

const BoundingBox<short> &AEntity::box() const
{
    return _box;
}

void AEntity::move(short dx, short dy)
{
    if (_exist) {
        _box.x += dx;
        _box.y += dy;
    }
}

int AEntity::life() const
{
    return _life;
}

void AEntity::setLife(int life)
{
    _life = life;
}

void AEntity::kill()
{
    _exist = false;
}

bool AEntity::exists() const
{
    return _exist;
}

bool AEntity::isDeletable() const
{
    return _deletable;
}
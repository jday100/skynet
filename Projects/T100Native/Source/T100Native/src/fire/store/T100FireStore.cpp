#include "T100FireStore.h"

#include "T100Cuboid.h"

T100FireStore::T100FireStore()
{
    //ctor
}

T100FireStore::~T100FireStore()
{
    //dtor
}

T100BOOL T100FireStore::Load(T100ENTITY_VECTOR& entities)
{
    T100Cuboid*     cuboid      = T100NEW T100Cuboid();

    cuboid->Create(1, 1, 1);

    entities.push_back(cuboid);
}

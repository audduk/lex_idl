#include "testServer.h"

namespace SUMMATOR_server {

void testServer::add(numPair pair)
{
    printf("SERVER\t%d+%d\n", pair.first, pair.second );
    emit add_result( pair.first + pair.second );
}

void testServer::sub(int first, int second)
{
    emit sub_result( first - second );
}

}

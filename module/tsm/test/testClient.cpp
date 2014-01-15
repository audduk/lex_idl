#include "testClient.h"

namespace SUMMATOR_client {

void testClient::add_result(int result)
{
    printf("CLIENT\nADD RESULT = %d\n", result);
}

void testClient::sub_result(int result)
{
    printf("CLIENT\tSUB RESULT = %d\n", result);
}

}

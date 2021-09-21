// Implementation of Response (I know that I can put this in the header file!)
#include <vector>
#include "Response.h"
#include "Buffer.h"
#include "Packet.h"

using namespace std;

  Response::Response(int processTime) { //Initializes Response object with processTime
    responseTime = processTime;
  }

  int Response::getResponseTime() {
    return responseTime;
  }

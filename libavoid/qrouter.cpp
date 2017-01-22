#include "qrouter.h"

namespace Avoid
{
QRouter::QRouter()
    : Router(Avoid::OrthogonalRouting)
{
    setRoutingParameter(Avoid::shapeBufferDistance, 5.0);
    setRoutingParameter(Avoid::idealNudgingDistance, 5.0);
    setRoutingOption(Avoid::nudgeOrthogonalSegmentsConnectedToShapes, true);
}
}

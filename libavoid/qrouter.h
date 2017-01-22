#pragma once

#include "libavoid.h"
#include "connend.h"
#include "connector.h"
#include "router.h"
#include "shape.h"


#include <QObject>

namespace Avoid
{
class QRouter : public Router
{
public:
    QRouter();
};
}

#pragma once

#include "libavoid/libavoid.h"
#include "libavoid/connend.h"
#include "libavoid/connector.h"
#include "libavoid/router.h"
#include "libavoid/shape.h"

#include <QObject>

namespace Avoid
{
class QRouter : public Router
{
public:
    QRouter();
};
}

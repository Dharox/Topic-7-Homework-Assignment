#include "PrecondViolatedExcept.h"

PrecondViolatedExcept::PrecondViolatedExcept(const std::string& message) : std::logic_error("Precondidtion violated exception: " + message)
{
}
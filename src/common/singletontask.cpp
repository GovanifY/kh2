#include "./types.h"
#include "task.hpp"


class TASK_MANAGER;

namespace SINGLETON_TASK {

void start(TASK_MANAGER* a0);
void Finalizer(TASK* a0);

} // namespace SINGLETON_TASK

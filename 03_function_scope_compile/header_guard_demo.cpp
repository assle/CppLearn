#include <iostream>

#include "build_config.h"
#include "build_config.h"

int main()
{
    BuildMode mode = BuildMode::Debug;

    std::cout << "max_retry_count: " << max_retry_count << std::endl;
    std::cout << "build mode value: " << static_cast<int>(mode) << std::endl;

    return 0;
}

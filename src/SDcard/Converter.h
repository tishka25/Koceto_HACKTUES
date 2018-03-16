#include <cstddef>

#define CW 1
#define VERTICAL 2
#define CCW 3
#define COUNTER_CLOCK_WISE CCW
#define CLOCK_WISE CW


class Converter{
  public:
    Converter();
    template <size_t rows, size_t cols>
    static void convert1Dto2Darr(unsigned int *arr1D,int (&arr2D)[rows][cols]);
    void flipSprite(unsigned char *arr,unsigned char *arrNew, int rotation);
};

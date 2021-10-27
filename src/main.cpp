#include <../gba/gba.hpp>

using namespace gba;

using video_memory_type = std::array<std::array<uint16, 240>, 160>;

static auto& video_memory = *reinterpret_cast<video_memory_type *>( 0x06000000 );

struct bgr555_type {
    uint16 red : 5;
    uint16 green : 5;
    uint16 blue : 5;
};

int main() {
    reg::dispcnt::write( { .mode = 3, .layer_background_2 = true } );
    
    video_memory[80][120] = uint_cast( bgr555_type { .red = 31 } );
    video_memory[80][136] = uint_cast( bgr555_type { .green = 31 } );
    video_memory[96][120] = uint_cast( bgr555_type { .blue = 31 } );
    
    while ( true ) {}
    __builtin_unreachable();
}

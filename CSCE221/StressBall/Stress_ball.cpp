#include "Stress_ball.h"
#include <iostream>

// a
Stress_ball::Stress_ball() : color(Stress_ball_colors(rand()%4)), size(Stress_ball_sizes(rand()%3)) {}
// b
Stress_ball::Stress_ball(Stress_ball_colors c, Stress_ball_sizes s) : color(c), size(s) {}
// c
Stress_ball_colors Stress_ball::get_color() const
{
    const Stress_ball_colors cl = color;
    return cl;
}
// d
Stress_ball_sizes Stress_ball::get_size() const
{
    const Stress_ball_sizes sz = size;
    return sz;
}
// e
bool Stress_ball::operator==(const Stress_ball& sb)
{
    if (this->color == sb.color && this->size == sb.size)
    {
        return true;
    } 
    else 
    {
        return false;
    }
}
// f
std::ostream& operator<<(std::ostream& o, const Stress_ball& sb) 
{
    o << '(';
    switch (sb.get_color()) {
        case (Stress_ball_colors::blue) : o << "blue";
            break;
        case (Stress_ball_colors::red) : o << "red";
            break;
        case (Stress_ball_colors::yellow) : o << "yellow";
            break;
        case (Stress_ball_colors::green) : o << "green";
            break;
        default : o << "No color";
    }
    o << ", ";
    switch (sb.get_size()) {
        case (Stress_ball_sizes::large) : o << "large";
            break;
        case (Stress_ball_sizes::medium) : o << "medium";
            break;
        case (Stress_ball_sizes::small) : o << "small";
            break;
        default : o << "No size";
    }
    o << ")\n";
    return o;
}
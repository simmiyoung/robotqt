#ifndef Position_h
#define Position_h
class Position
{
	private:
			short x;
		short y;
		unsigned short degree;

	public:
		Position(): x(0), y(0), degree(0) {};
		Position(short _x, short _y, short _d) : x( _x ), y( _y ), degree( _d ) {};
		Position(const Position& obj);
		//virtual ~Position();
		inline void Set(Position& obj);
		void Set(short& x, short& y, short& degree);
		short GetX() const;
		short GetY() const;
		short GetDegree() const;

		Position & operator+(const Position &);
		Position & operator-(const Position &);
	//	inline Position & operator=(const Position & p2);
};
#endif

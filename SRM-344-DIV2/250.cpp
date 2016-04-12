#include <string>
#include <map>


class Chessboard{
	private:
	std::map <int, std::string>  x {
	    std::make_pair (0, "a"),
	    std::make_pair (1, "b"),
	    std::make_pair (2, "c"),
	    std::make_pair (3, "d"),
	    std::make_pair (4, "e"),
	    std::make_pair (5, "f"),
	    std::make_pair (6, "g"),
	    std::make_pair (7, "h")
    };
    
    	std::map <char, int>  y {
	    std::make_pair ('a', 0),
	    std::make_pair ('b', 1),
	    std::make_pair ('c', 2),
	    std::make_pair ('d', 3),
	    std::make_pair ('e', 4),
	    std::make_pair ('f', 5),
	    std::make_pair ('g', 6),
	    std::make_pair ('h', 7)
    };
    
	public:
	std::string changeNotation(std::string cell){
		std::string ans;
		int row, col;
		if(cell[0] >= '0' && cell[0] <= '9'){
			int numCell = std::stoi ( cell ) - 1;
			col = numCell % 8;
			row = numCell / 8;
			ans = x[col] + std::to_string(row+1);
		} else {
			int numCell = (cell[1] - '1')*8 + y[ cell[0] ] + 1;
			ans = std::to_string(numCell);
		}
		return ans;
	}

};

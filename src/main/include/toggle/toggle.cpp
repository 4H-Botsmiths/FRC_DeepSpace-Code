#include <functional>
#include <vector>
#include <array>

template <class T>
class toggle { //have toggler of N length
private:
	bool last=false;
	unsigned int index=0;

	std::vector<std::function<void(T)>> funcs;
	std::vector<T> params;
	
public:
	toggle(std::vector<std::function<void(T)>> fs, std::vector<T> ps) : funcs(fs), params(ps) {}
	
	void toggleIf(bool condition) { //tests if the condition is true, if so run the correct funtions
		if (!last&condition) {
			funcs[index](params[index]); //run which ever function is next
			index==funcs.size()-1?index=0:index++; //switch to next function
		}
		last=condition;
	}
};

template <class T>
class toggle2 { //have toggler of 2 length
private:
	bool last=false;
	bool runfirst=true; //run f_a() if true, f_b() else

	std::function<void(T)> f_a;
	std::function<void(T)> f_b;
	std::vector<T> params;
	
public:
	toggle2(std::function<void(T)> a, std::function<void(T)> b, std::vector<T> p) : f_a(a), f_b(b), params(p) {}

	void toggleIf(bool condition) { //tests if the condition is true, if so run the correct funtions
		if (!last&condition) {
			runfirst?f_a(params[0]):f_b(params[1]); //run which ever function is next
			runfirst=!runfirst; //invert function to run next
		}
		last=condition;
	}
};
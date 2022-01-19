#include "math_utility.hpp"

/**
 * is an int or a double
 * return 1 if it is an int or 0 if it is a double
 */

bool	is_an_int(double number)
{
	return(((double)((int)number) == number));
}

/**
 * Square root function
 * use the babylonian method
 * first part choose a good start number
 * second part apply the algorithm
 */

double ft_sqrt(double number)
{
	const double precision = 0.0000001;
	double buffer = 100;
	double puiss_100 = 0;
	double approximation = 7.00000000000;
	double last_approximation;
	int nbr_iteration = 1;

	if (number < 0)
	      throw std::domain_error("Can't calculate negative square");
	while (number > buffer)
	{
		buffer *= 100;
		++puiss_100;
	}
	for (int i = 0; i < puiss_100; ++i)
		approximation *= 10;

	//apply algorithm
	last_approximation = approximation;
	approximation = 0.5 * (last_approximation + number / last_approximation);

	while (ft_abs(approximation - last_approximation) > precision)
	{
		++nbr_iteration;
		last_approximation = approximation;
		approximation = 0.5 * (last_approximation + number / last_approximation);
	}
	return(approximation);
}

/**
 * @brief write the number as a fraction
 *
 * @param number
 * @param cycles
 * @param precision
 */
void as_fraction(double number, int cycles, double precision){
    int sign  = number > 0 ? 1 : -1;
    number = number * sign; //abs(number);
    double new_number, whole_part;
    double decimal_part =  number - (int)number;
    int counter = 0;

    double vec_1[2] = {double((int)number), 1};
    double vec_2[2] = {1, 0};
    double temporary[2];


    while(decimal_part > precision & counter < cycles)
    {
        new_number = 1 / decimal_part;
        whole_part = (int) new_number;

        temporary[0]= vec_1[0];
        temporary[1]= vec_1[1];
        vec_1[0] = whole_part * temporary[0] + vec_2[0];
        vec_1[1] = whole_part * temporary[1] + vec_2[1];
        vec_2[0] = temporary[0];
        vec_2[1] = temporary[1];

        decimal_part = new_number - whole_part;
        counter += 1;
    }
    std::cout<<"x: "<< number <<"\tFraction: " << sign * vec_1[0]<<'/'<< vec_1[1]<< std::endl;
}
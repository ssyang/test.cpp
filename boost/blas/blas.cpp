// blas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/*
#ifdef _WIN32
#undef __STRICT_ANSI__
#endif
*/

#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>

const boost::numeric::ublas::matrix<double> CreateMatrix(
    const std::size_t n_rows,
    const std::size_t n_cols,
    const std::vector<double>& v)
{
    assert(n_rows * n_cols == v.size());
    boost::numeric::ublas::matrix<double> m(n_rows, n_cols);
    for (std::size_t row = 0; row != n_rows; ++row)
    {
        for (std::size_t col = 0; col != n_cols; ++col)
        {
            m(row, col) = v[(col * n_rows) + row];
        }
    }
    return m;
}

//Chop returns a std::vector of sub-matrices
//[ A at [0]   B at [1] ]
//[ C at [2]   D at [4] ]
const std::vector<boost::numeric::ublas::matrix<double> > Chop(
    const boost::numeric::ublas::matrix<double>& m)
{
    //using boost::numeric::ublas::range;
    //using boost::numeric::ublas::matrix;
    //using boost::numeric::ublas::matrix_range;
    std::vector<boost::numeric::ublas::matrix<double> > v;
    v.reserve(4);
    const int midy = m.size1() / 2;
    const int midx = m.size2() / 2;
    const boost::numeric::ublas::matrix_range<const boost::numeric::ublas::matrix<double> > top_left(m, boost::numeric::ublas::range(0, midy), boost::numeric::ublas::range(0, midx));
    const boost::numeric::ublas::matrix_range<const boost::numeric::ublas::matrix<double> > bottom_left(m, boost::numeric::ublas::range(midy, m.size1()), boost::numeric::ublas::range(0, midx));
    const boost::numeric::ublas::matrix_range<const boost::numeric::ublas::matrix<double> > top_right(m, boost::numeric::ublas::range(0, midy), boost::numeric::ublas::range(midx, m.size2()));
    const boost::numeric::ublas::matrix_range<const boost::numeric::ublas::matrix<double> > bottom_right(m, boost::numeric::ublas::range(midy, m.size1()), boost::numeric::ublas::range(midx, m.size2()));
    v.push_back(boost::numeric::ublas::matrix<double>(top_left));
    v.push_back(boost::numeric::ublas::matrix<double>(top_right));
    v.push_back(boost::numeric::ublas::matrix<double>(bottom_left));
    v.push_back(boost::numeric::ublas::matrix<double>(bottom_right));
    return v;
}

bool IsAboutEqual(const double x, const double y) { return std::abs(x - y) < 0.00001; }

int main()
{
    //using boost::numeric::ublas::matrix;
    //using boost::numeric::ublas::prod;
    //using boost::numeric::ublas::vector;
    {
        //                     [ 1.0 ] | [ 2.0   3.0 ]
        // [ 1.0 2.0 3.0 ]     --------+--------------
        // [ 4.0 5.0 6.0 ]     [ 4.0 ] | [ 5.0   6.0 ]
        // [ 7.0 8.0 9.0 ] ->  [ 7.0 ] | [ 8.0   9.0 ]
        const boost::numeric::ublas::matrix<double> m = CreateMatrix(3, 3, { 1.0,4.0,7.0,2.0,5.0,8.0,3.0,6.0,9.0 });
        assert(m(0, 0) == 1.0); assert(m(0, 1) == 2.0); assert(m(0, 2) == 3.0);
        assert(m(1, 0) == 4.0); assert(m(1, 1) == 5.0); assert(m(1, 2) == 6.0);
        assert(m(2, 0) == 7.0); assert(m(2, 1) == 8.0); assert(m(2, 2) == 9.0);
        const std::vector<boost::numeric::ublas::matrix<double> > n = Chop(m);
        assert(n.size() == 4);
        std::wclog
            << L"m   : " << m << L'\n'
            << L"n[0]: " << n[0] << L'\n'
            << L"n[1]: " << n[1] << L'\n'
            << L"n[2]: " << n[2] << L'\n'
            << L"n[3]: " << n[3] << L'\n';
        assert(n[0].size1() == 1);
        assert(n[0].size2() == 1);
        assert(n[1].size1() == 1);
        assert(n[1].size2() == 2);
        assert(n[2].size1() == 2);
        assert(n[2].size2() == 1);
        assert(n[3].size1() == 2);
        assert(n[3].size2() == 2);
        assert(n[0].size1() + n[2].size1() == m.size1());
        assert(n[1].size1() + n[3].size1() == m.size1());
        assert(n[0].size2() + n[1].size2() == m.size2());
        assert(n[2].size2() + n[3].size2() == m.size2());
    }
    {
        const boost::numeric::ublas::matrix<double> m = CreateMatrix(5, 5,
            {
              1.0, 6.0,11.0,16.0,21.0,
              2.0, 7.0,12.0,17.0,22.0,
              3.0, 8.0,13.0,18.0,23.0,
              4.0, 9.0,14.0,19.0,24.0,
              5.0,10.0,15.0,20.0,25.0
            }
        );
        assert(m(0, 0) == 1.0); assert(m(0, 1) == 2.0); assert(m(0, 2) == 3.0); assert(m(0, 3) == 4.0); assert(m(0, 4) == 5.0);
        assert(m(1, 0) == 6.0); assert(m(1, 1) == 7.0); assert(m(1, 2) == 8.0); assert(m(1, 3) == 9.0); assert(m(1, 4) == 10.0);
        assert(m(2, 0) == 11.0); assert(m(2, 1) == 12.0); assert(m(2, 2) == 13.0); assert(m(2, 3) == 14.0); assert(m(2, 4) == 15.0);
        assert(m(3, 0) == 16.0); assert(m(3, 1) == 17.0); assert(m(3, 2) == 18.0); assert(m(3, 3) == 19.0); assert(m(3, 4) == 20.0);
        assert(m(4, 0) == 21.0); assert(m(4, 1) == 22.0); assert(m(4, 2) == 23.0); assert(m(4, 3) == 24.0); assert(m(4, 4) == 25.0);
        const std::vector<boost::numeric::ublas::matrix<double> > n = Chop(m);
        assert(n.size() == 4);
        std::wclog
            << L"m   : " << m << L'\n'
            << L"n[0]: " << n[0] << L'\n'
            << L"n[1]: " << n[1] << L'\n'
            << L"n[2]: " << n[2] << L'\n'
            << L"n[3]: " << n[3] << L'\n';
        assert(n[0].size1() == 2);
        assert(n[0].size2() == 2);
        assert(n[1].size1() == 2);
        assert(n[1].size2() == 3);
        assert(n[2].size1() == 3);
        assert(n[2].size2() == 2);
        assert(n[3].size1() == 3);
        assert(n[3].size2() == 3);
        assert(n[0].size1() + n[2].size1() == m.size1());
        assert(n[1].size1() + n[3].size1() == m.size1());
        assert(n[0].size2() + n[1].size2() == m.size2());
        assert(n[2].size2() + n[3].size2() == m.size2());
    }
}

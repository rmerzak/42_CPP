/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:04:26 by rmerzak           #+#    #+#             */
/*   Updated: 2023/08/21 14:48:04 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <sstream>
#include <iomanip>
PmergeMe::PmergeMe(char **argv)
{
    for (int i = 1; argv[i]; i++)
    {
        for(size_t j = 0; j < strlen(argv[i]); j++) {
            if(!isdigit(argv[i][j]) /*&& argv[i][j] != '-' && argv[i][j] != '+'*/) {
                std::cout << "Error: Invalid token " << argv[i] << std::endl;
                return;
            }
        }
        std::string str(argv[i]);
        long num = ft_atoi(argv[i]);
        if((num < 0 || num > INT_MAX)) {
            std::cout << "Error: Invalid token " << argv[i] << std::endl;
            return;
        }
        Pmerge.push_back(num);
        deq.push_back(num);
    }
}

PmergeMe::~PmergeMe() {
}




long PmergeMe::ft_atoi(const char *str)
{
	long	sgn;
	long	res;
	int		i;

	sgn = 1;
	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\f'
		|| str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v' )
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgn = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sgn);
}
bool PmergeMe::Parsenumbers(const std::string& value) {
    int i = 0;

    if (value.empty())
        return false;
    while (value[i]) {
        if (!std::isdigit(value[i]) && value[i] != '-' && value[i] != '+') {
            return false;
        }
        i++;
    }

    return true;
}
std::vector<std::pair<int, int> > PmergeMe::create_pairs(const std::vector<int> &a)
{
    std::vector<std::pair<int, int> > split_array;
    std::vector<int> temp_array;

    for (size_t i = 0; i < a.size(); i++)
    {
        size_t temp_length = temp_array.size();
        if (temp_length == 1)
        {
            temp_array.push_back(a[i]);
            split_array.push_back(std::make_pair(temp_array[0], temp_array[1]));
            temp_array.clear();
        }
        else if (temp_length == 0)
        {
            temp_array.push_back(a[i]);
        }
    }

    return split_array;
}

std::vector<std::pair<int, int> > PmergeMe::sort_each_pair(const std::vector<std::pair<int, int> > &split_array)
{
    std::vector<std::pair<int, int> > sorted_split_array = split_array;

    for (size_t i = 0; i < sorted_split_array.size(); i++)
    {
        if (sorted_split_array[i].second != -1 && sorted_split_array[i].first > sorted_split_array[i].second)
        {
            std::swap(sorted_split_array[i].first, sorted_split_array[i].second);
        }
    }

    return sorted_split_array;
}
void PmergeMe::insert_deque(std::pair<int, int> element, std::deque<std::pair<int, int> > &A, int n)
{
    if (n < 0)
    {
        A[0] = element;
    }
    else if (element.second >= A[n].second)
    {
        if (n == static_cast<int>(A.size()) - 1)
        {
            A.push_back(element);
        }
        else
        {
            A[n + 1] = element;
        }
    }
    else
    {
        if (n == static_cast<int>(A.size()) - 1)
        {
            A.push_back(A[n]);
        }
        else
        {
            A[n + 1] = A[n];
            insert_deque(element, A, n - 1);
        }
    }
}
void PmergeMe::insert(std::pair<int, int> element, std::vector<std::pair<int, int> > &A, int n)
{
    if (n < 0)
    {
        A[0] = element;
    }
    else if (element.second >= A[n].second)
    {
        if (n == static_cast<int>(A.size()) - 1)
        {
            A.push_back(element);
        }
        else
        {
            A[n + 1] = element;
        }
    }
    else
    {
        if (n == static_cast<int>(A.size()) - 1)
        {
            A.push_back(A[n]);
        }
        else
        {
            A[n + 1] = A[n];
            insert(element, A, n - 1);
        }
    }
}
void PmergeMe::insertion_sort_pairs(std::vector<std::pair<int, int> > &A, int n)
{
    if (n < 1)
    {
        return;
    }
    else
    {
        insertion_sort_pairs(A, n - 1);
        insert(A[n], A, n - 1);
    }
};


void PmergeMe::insertion_sort_pairs_deque(std::deque<std::pair<int, int> > &A, int n)
{
    if (n < 1)
    {
        return;
    }
    else
    {
        insertion_sort_pairs_deque(A, n - 1);
        insert_deque(A[n], A, n - 1);
    }
};

int PmergeMe::jacobsthal_memoized(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    return jacobsthal_memoized(n - 1) + 2 * jacobsthal_memoized(n - 2);
}

std::vector<int> PmergeMe::build_jacob_insertion_sequence(int array_len)
{
    std::vector<int> end_sequence;
    int jacob_index = 1;
    while (jacobsthal_memoized(jacob_index) < array_len)
    {
        int temp = jacobsthal_memoized(jacob_index);
        end_sequence.push_back(temp);
        jacob_index = jacob_index + 1;
    }
    end_sequence.push_back(jacobsthal_memoized(jacob_index));
    return end_sequence;
}
void PmergeMe::sort_by_larger_value(std::vector<std::pair<int, int> > &sorted_split_array)
{
    insertion_sort_pairs(sorted_split_array, sorted_split_array.size() - 1);
}
void PmergeMe::sort_by_larger_value_deque(std::deque<std::pair<int, int> > &sorted_split_array)
{
    insertion_sort_pairs_deque(sorted_split_array, sorted_split_array.size() - 1);
}
int PmergeMe::binary_search_insertion_index(const std::vector<int> &sorted_array, int value)
{
    int left = 0;
    int right = sorted_array.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (sorted_array[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}
int PmergeMe::binary_search_insertion_index_deque(const std::deque<int> &sorted_array, int value)
{
    int left = 0;
    int right = sorted_array.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (sorted_array[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}

std::vector<int> PmergeMe::create_s(const std::vector<std::pair<int, int> > &sorted_split_array, int straggler)
{
    std::vector<int> S;
    std::vector<int> pend;

    for (size_t i = 0; i < sorted_split_array.size(); i++)
    {
        S.push_back(sorted_split_array[i].second);
        pend.push_back(sorted_split_array[i].first);
    }
    S.insert(S.begin(), pend[0]);
    std::vector<int> indexSequence;

    std::vector<int> jacob_insertion_sequence = build_jacob_insertion_sequence(pend.size());
    int jacob_idx, lastindex = 1;
    for (size_t i = 0; i < jacob_insertion_sequence.size(); i++)
    {
        // insert form last index to jacob index into S vector
        jacob_idx = jacob_insertion_sequence[i];
        while (lastindex <= jacob_idx)
        {
            if (jacob_idx <= static_cast<int>(pend.size()) && lastindex < jacob_idx)
            {
                int item = pend[jacob_idx - 1];
                int insertion_index = binary_search_insertion_index(S, item);
                S.insert(S.begin() + insertion_index, item);
            }
            jacob_idx = jacob_idx - 1;
        }
        lastindex = jacob_insertion_sequence[i];
    }
    if (straggler != -1)
    {
        int insertion_index = binary_search_insertion_index(S, straggler);
        S.insert(S.begin() + insertion_index, straggler);
    }
    return S;
}

std::deque<int> PmergeMe::create_s_deque(const std::deque<std::pair<int, int> > &sorted_split_array, int straggler)
{
    std::deque<int> S;
    std::deque<int> pend;

    for (size_t i = 0; i < sorted_split_array.size(); i++)
    {
        S.push_back(sorted_split_array[i].second);
        pend.push_back(sorted_split_array[i].first);
    }

    S.insert(S.begin(), pend[0]);

    std::deque<int> indexSequence;
    std::string last = "default";

    std::vector<int> jacob_insertion_sequence = build_jacob_insertion_sequence(pend.size());
    int jacob_idx, lastindex = 1;
    for (size_t i = 0; i < jacob_insertion_sequence.size(); i++)
    {
        // insert form last index to jacob index into S vector
        jacob_idx = jacob_insertion_sequence[i];
        while (lastindex <= jacob_idx)
        {
            if (jacob_idx <= static_cast<int>(pend.size()) && lastindex < jacob_idx)
            {
                int item = pend[jacob_idx - 1];
                int insertion_index = binary_search_insertion_index_deque(S, item);
                S.insert(S.begin() + insertion_index, item);
            }
            jacob_idx = jacob_idx - 1;
        }
        lastindex = jacob_insertion_sequence[i];
    }
    if (straggler != -1)
    {
        int insertion_index = binary_search_insertion_index_deque(S, straggler);
        S.insert(S.begin() + insertion_index, straggler);
    }
    return S;
}

std::vector<int> PmergeMe::merge_insertion_sort(const std::vector<int> &A)
{
    clock_t start, end;
    start = clock();
    bool hasStraggler = A.size() % 2 != 0;
    int straggler = -1;

    if (hasStraggler)
    {
        straggler = A[A.size() - 1];
    }
    std::vector<std::pair<int, int> > split_array = create_pairs(A);
    std::vector<std::pair<int, int> > sorted_split_array = sort_each_pair(split_array);
    sort_by_larger_value(sorted_split_array);
    std::vector<int> S = create_s(sorted_split_array, straggler);
    ///check is sorted
    end = clock();
    double T = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout<< std::fixed << std::setprecision(5) <<"Time to process a range of " << this->Pmerge.size() << " elements with std::vector : "<<T<<" us"<< std::endl;
    return S;
}

/////////////////////////////////////////////////////

std::deque<int> PmergeMe::merge_insertion_sort_deque(const std::deque<int> &A)
{
    clock_t start, end;
    start = clock();

    bool hasStraggler = A.size() % 2 != 0;
    int straggler = -1;

    if (hasStraggler)
    {
        straggler = A[A.size() - 1];
    }
    std::deque<std::pair<int, int> > split_array = create_pairs_deque(A);
    std::deque<std::pair<int, int> > sorted_split_array = sort_each_pair_deque(split_array);
    sort_by_larger_value_deque(sorted_split_array);
    std::deque<int> S = create_s_deque(sorted_split_array, straggler);
    end = clock();
    double T = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout<< std::fixed << std::setprecision(5) <<"Time to process a range of " << this->deq.size() << " elements with std::deque : "<<T<<" us"<< std::endl;
    return S;
}

std::deque<std::pair<int, int> > PmergeMe::create_pairs_deque(const std::deque<int> &a)
{
    std::deque<std::pair<int, int> > split_array;
    std::deque<int> temp_array;

    for (size_t i = 0; i < a.size(); i++)
    {
        size_t temp_length = temp_array.size();
        if (temp_length == 1)
        {
            temp_array.push_back(a[i]);
            split_array.push_back(std::make_pair(temp_array[0], temp_array[1]));
            temp_array.clear();
        }
        else if (temp_length == 0)
        {
            temp_array.push_back(a[i]);
        }
    }

    return split_array;
}
std::vector<int> PmergeMe::getPmerge(void) {
    return this->Pmerge;
}
void PmergeMe::setPmerge(std::vector<int> merge) {
    this->Pmerge.clear();
    for(size_t i = 0; i < merge.size(); i++) {
        this->Pmerge.push_back(merge[i]);
    }
}
std::deque<int> PmergeMe::getDeq(void) {
    return this->deq;
}
void PmergeMe::setDeq(std::deque<int> q) {
    this->deq.clear();
    for(size_t i = 0; i < q.size(); i++) {
        this->deq.push_back(q[i]);
    }
}
PmergeMe::PmergeMe(const PmergeMe &a) {
    this->Pmerge.clear();
    for (size_t i = 0; i < a.Pmerge.size(); i++) {
        this->Pmerge.push_back(a.Pmerge[i]);
    }

    this->deq.clear();
    for (size_t i = 0; i < a.deq.size(); i++) {
        this->deq.push_back(a.deq[i]);
    }
}

PmergeMe& PmergeMe::operator=(const PmergeMe &a) {
    if (this != &a) { // Check for self-assignment
        this->Pmerge.clear();
        for (size_t i = 0; i < a.Pmerge.size(); i++) {
            this->Pmerge.push_back(a.Pmerge[i]);
        }

        this->deq.clear();
        for (size_t i = 0; i < a.deq.size(); i++) {
            this->deq.push_back(a.deq[i]);
        }
    }
    return *this;
}

void PmergeMe::mergeInsertion(void) {
    std::cout << "Before: ";
    for(size_t i = 0; i < this->Pmerge.size(); i++) {
        std::cout << this->Pmerge[i] << " ";
    }
    std::cout << std::endl;
    clock_t start1, end1;
    start1 = clock();
    bool hasStraggler = this->Pmerge.size() % 2 != 0;
    int straggler = -1;

    if (hasStraggler)
    {
        straggler = this->Pmerge[this->Pmerge.size() - 1];
    }
    std::vector<std::pair<int, int> > split_array_v = create_pairs(this->Pmerge);
    std::vector<std::pair<int, int> > sorted_split_array_v = sort_each_pair(split_array_v);
    sort_by_larger_value(sorted_split_array_v);
    std::vector<int> vec = create_s(sorted_split_array_v, straggler);
    end1 = clock();
    double T1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC;
    std::cout << "After: ";
    for(size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout<< std::fixed << std::setprecision(5) <<"Time to process a range of " << this->Pmerge.size() << " elements with std::vector : "<<T1<<" us"<< std::endl;
    clock_t start2, end2;
    start2 = clock();
    std::deque<std::pair<int, int> > split_array = create_pairs_deque(this->deq);
    std::deque<std::pair<int, int> > sorted_split_array = sort_each_pair_deque(split_array);
    sort_by_larger_value_deque(sorted_split_array);
    std::deque<int> deque = create_s_deque(sorted_split_array, straggler);
    end2 = clock();
    double T2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC;
    std::cout<< std::fixed << std::setprecision(5) <<"Time to process a range of " << this->deq.size() << " elements with std::deque : "<<T2<<" us"<< std::endl;
}


std::deque<std::pair<int, int> > PmergeMe::sort_each_pair_deque(const std::deque<std::pair<int, int> > &split_array)
{
    std::deque<std::pair<int, int> > sorted_split_array = split_array;

    for (size_t i = 0; i < sorted_split_array.size(); i++)
    {
        if (sorted_split_array.at(i).second != -1 && sorted_split_array[i].first > sorted_split_array.at(i).second)
        {
            std::swap(sorted_split_array[i].first, sorted_split_array[i].second);
        }
    }

    return sorted_split_array;
}


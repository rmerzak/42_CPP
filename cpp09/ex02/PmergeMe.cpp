/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:04:26 by rmerzak           #+#    #+#             */
/*   Updated: 2023/08/16 19:00:27 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv)
{
    for (int i = 1; argv[i]; i++)
    {
        // check if argv[i] is a number and is digit and not negative
        for(size_t j = 0; j < strlen(argv[i]); j++) {
            if(!isdigit(argv[i][j])) {
                std::cout << "Error: Invalid token " << argv[i] << std::endl;
                return;
            }
        }
        Pmerge.push_back(std::stoi(argv[i]));
    }
    this->merge_insertion_sort(Pmerge);
}

PmergeMe::~PmergeMe()
{
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
            // } else if (split_array.size() * 2 == a.size() - 1) {
            //     std::cout << "one time: " << a[i] << std::endl;
            //     split_array.push_back(std::make_pair(a[i], -1));
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

    // Initialize the memoization table
    //jacobsthal_memo.assign(array_len + 1, -1);
    while (jacobsthal_memoized(jacob_index) < array_len)
    {
        int temp = jacobsthal_memoized(jacob_index);
        end_sequence.push_back(temp);
        jacob_index = jacob_index + 1;
    }
    end_sequence.push_back(jacobsthal_memoized(jacob_index));
    return end_sequence;
}

// Recursively sort the larger set of elements into sorted set
void PmergeMe::sort_by_larger_value(std::vector<std::pair<int, int> > &sorted_split_array)
{
    insertion_sort_pairs(sorted_split_array, sorted_split_array.size() - 1);
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
    std::string last = "default";

    std::vector<int> jacob_insertion_sequence = build_jacob_insertion_sequence(pend.size());

    // using jacobsthal sequence and pend vector push to S vector sorted elements
    int jacob_idx, lastindex = 1;
    // lastindex, jacob_idx
    for (size_t i = 0; i < jacob_insertion_sequence.size(); i++)
    {
        // insert form last index to jacob index into S vector
        jacob_idx = jacob_insertion_sequence[i];
        while (lastindex <= jacob_idx)
        {
        // std::cout << "lastindex: " << lastindex << " jacob_idx: " << jacob_idx << " pend size " << pend.size() << std::endl;
            if (jacob_idx <= static_cast<int>(pend.size()) && lastindex < jacob_idx)
            {
                int item = pend[jacob_idx - 1];
                int insertion_index = binary_search_insertion_index(S, item);
                // std::cout << "item: " << item << " " << jacob_insertion_sequence[i] << std::endl;
                S.insert(S.begin() + insertion_index, item);
            }
            jacob_idx = jacob_idx - 1;
            // S.insert(S.begin() + insertion_index, item);
        }
        lastindex = jacob_insertion_sequence[i];
    }
    // std::cout << "straggler: " << straggler << std::endl;
    if (straggler != -1)
    {
        int insertion_index = binary_search_insertion_index(S, straggler);
        S.insert(S.begin() + insertion_index, straggler);
    }
    return S;
}

std::vector<int> PmergeMe::merge_insertion_sort(const std::vector<int> &A)
{
    std::cout << "Starting Array:" << std::endl;
    for (size_t i = 0; i < A.size(); i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    bool hasStraggler = A.size() % 2 != 0;
    int straggler = -1;

    if (hasStraggler)
    {
        straggler = A[A.size() - 1];
    }
    std::vector<std::pair<int, int> > split_array = create_pairs(A);
    // ptint split_array vector
    // for (size_t i = 0; i < split_array.size(); i++)
    // {
    //     std::cout << " split array " << split_array[i].first << " " << split_array[i].second << std::endl;
    // }
    std::vector<std::pair<int, int> > sorted_split_array = sort_each_pair(split_array);
    // for (size_t i = 0; i < sorted_split_array.size(); i++)
    // {
    //     std::cout << "0 sorted split array " << sorted_split_array[i].first << " " << sorted_split_array[i].second << std::endl;
    // }
    sort_by_larger_value(sorted_split_array);

    // for (size_t i = 0; i < sorted_split_array.size(); i++)
    // {
    //     std::cout << "1 sorted split array " << sorted_split_array[i].first << " " << sorted_split_array[i].second << std::endl;
    // }
    std::cout << "--------------------------------------" << std::endl;
    std::vector<int> S = create_s(sorted_split_array, straggler);
    for(size_t i = 0; i < S.size(); i++) {
        std::cout << S[i] << " ";
    }
    std::cout << std::endl;
    return S;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:04:29 by rmerzak           #+#    #+#             */
/*   Updated: 2023/08/21 14:45:06 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include<deque>
class PmergeMe
{
private:
std::vector<int> Pmerge;
std::deque<int> deq;
public:
    PmergeMe(char **argv);
    ~PmergeMe();
    PmergeMe(const PmergeMe &a);
    PmergeMe &operator=(const PmergeMe &a);
    void setPmerge(std::vector<int> Pmerge);
    void setDeq(std::deque<int> deq);
    std::vector<int> getPmerge(void);
    std::deque<int> getDeq(void);
    bool Parsenumbers(const std::string& value);
    long ft_atoi(const char *str);
    std::vector<int> merge_insertion_sort(const std::vector<int> &A);
    std::vector<int> create_s(const std::vector<std::pair<int, int> > &sorted_split_array, int straggler);
    int binary_search_insertion_index(const std::vector<int> &sorted_array, int value);
    void sort_by_larger_value(std::vector<std::pair<int, int> > &sorted_split_array);
    std::vector<int> build_jacob_insertion_sequence(int array_len);
    int jacobsthal_memoized(int n);
    void insertion_sort_pairs(std::vector<std::pair<int, int> > &A, int n);
    void insert(std::pair<int, int> element, std::vector<std::pair<int, int> > &A, int n);
    std::vector<std::pair<int, int> > sort_each_pair(const std::vector<std::pair<int, int> > &split_array);
    std::vector<std::pair<int, int> > create_pairs(const std::vector<int> &a);
    ////////////////////////////
    std::deque<int> merge_insertion_sort_deque(const std::deque<int> &A);
    std::deque<int> create_s_deque(const std::deque<std::pair<int, int> > &sorted_split_array, int straggler);
    int binary_search_insertion_index_deque(const std::deque<int> &sorted_array, int value);
    void sort_by_larger_value_deque(std::deque<std::pair<int, int> > &sorted_split_array);
    void insertion_sort_pairs_deque(std::deque<std::pair<int, int> > &A, int n);
    void insert_deque(std::pair<int, int> element, std::deque<std::pair<int, int> > &A, int n);
    std::deque<std::pair<int, int> > sort_each_pair_deque(const std::deque<std::pair<int, int> > &split_array);
    std::deque<std::pair<int, int> > create_pairs_deque(const std::deque<int> &a);
    //////////////////////////////////
    void mergeInsertion(void);
};
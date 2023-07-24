/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:58:30 by nimai             #+#    #+#             */
/*   Updated: 2023/07/24 15:59:41 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SAMPLE_HPP_
#define _SAMPLE_HPP_

class CSample
{
	public:
		void set(int num);  // m_numに値を設定する
		int get();          // m_numの値を取得する
	private:
		int m_num;
};

#endif

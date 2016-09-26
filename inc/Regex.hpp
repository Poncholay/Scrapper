//
// Regex.hpp for  in /home/saurs_f/cpp_plazza/inc/
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.eu>
//
// Started on  Tue Apr 19 12:00:52 2016 Florian Saurs
// Last update Sun Apr 24 23:21:56 2016 guillaume wilmot
//

#ifndef REGEX_HPP_
# define REGEX_HPP_

# include <iostream>

class	Regex
{
public:
  Regex(const std::string &);
  ~Regex();

  std::string	match(const std::string &) const;
private:
  std::string	_pattern;
};

#endif /* !REGEX_HPP_ */

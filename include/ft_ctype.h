/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:26:24 by abronner          #+#    #+#             */
/*   Updated: 2025/06/29 22:40:55 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	In accordance with the standard library ft_ctype will take a integer as
//	input that is representable as an unsigned character.
//
//	Characters in ft_ctype are grouped into the following classes:
//	
//		DIGITS:
//			The set of whole numbers: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
//
//		HEXADECIMAL DIGITS:
//			The set of: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F, a, b,
//			c, d, e, f}
//
//		UPPER HEXADECIMAL DIGITS:
//			The set of: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F}
//
//		LOWER HEXADECIMAL DIGITS:
//			The set of: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e, f}
//
//		UPPERCASE LETTERS:
//			The set of lowercase letters: {A B C D E F G H I J K L M N O P Q R
//			S T U V W X Y Z}
//
//		LOWERCASE LETTERS:
//			The set of lowercase letters: {a b c d e f g h i j k l m n o p q r
//			s t u v w x y z}
//
//		LETTERS:
//			The set of lowercase and uppercase letters
//
//		ALPHANUMERICAL CHRARCTERS:
//			The set of lowercase letters, uppercase letters and digits
//
//		LOWER ALPHANUMERICAL CHARACTERS:
//			The set of lowercase letters and digits
//
//		UPPER ALPHANUMERICAL CHARACTERS:
//			The set of uppercase letters and digits
//
//		PUNCTUATION CHARACTERS:
//			The set of ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ¸
//			{ | } ~
//
//		GRAPHICAL CHARACTERS:
//			The set of alphanumerical characters and punctuation characters
//
//		SPACE CHARACTERS:
//			The set of tab, newline, vertical tab, form feed, carriage return,
//			and space
//
//		PRINTABLE CHARACTERS:
//			The set of graphical characters and space characters.
//
//		CONTROL CHARACTERS:
//			The set of ASCII characters (in octal) 000 to 037 and 177
//
//		BLANK CHARACTERS:
//			The set of space and tab and vertical tab

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

//	CHECKERS

//		ALPHA

int	ft_islower(int c);

int	ft_isupper(int c);

int	ft_isalpha(int c);

//		DIGIT

int	ft_isdigit(int c);

int	ft_isxdigit(int c);

int	ft_islowxdigit(int c);

int	ft_isupxdigit(int c);

//		ALNUM

int	ft_isalnum(int c);

int	ft_islowalnum(int c);

int	ft_isupalnum(int c);

//		GRAPHIC

int	ft_ispunct(int c);

int	ft_isgraph(int c);

//		PRINT

int	ft_isspace(int c);

int	ft_isprint(int c);

//		SPECIAL

int	ft_iscntrl(int c);

int	ft_isblank(int c);

int	ft_isascii(int c);

//	CONVERTERS

int	ft_tolower(int c);

int	ft_toupper(int c);

#endif

def main()
	puts "[0 - ножницы, 1 - камень, 2 - бумага]"
	computer_choise = rand(3)
	user_choise = gets.to_i

	result = user_choise - computer_choise
	print_result(result, computer_choise)

	if (result == 1) || (result == -2) 
		puts "Победа пользователя: компьютер выбрал " + convert_to_text(computer_choise)
	elsif  (result == -1) || (result == 2)  
		puts "Проигрыш пользователя: компьютер выбрал " + convert_to_text(computer_choise)
	else
		puts "Ничья: компьютер выбрал " + convert_to_text(computer_choise)
	end
end

def convert_to_text(digit)

	if digit == 0
		return "ножницы"
	elsif digit == 1
		return "камень"
	elsif digit == 2
		return "бумагу"
	else
		return ""
	end
end

main()
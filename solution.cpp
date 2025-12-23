#include <iostream>
#include <vector>
#include <string>

class PotionRecipe {
public:
	PotionRecipe(const std::string& potionName, const std::string& coreIngredient) { //생성자(이름,재료)
		PotionName_ = potionName;
		CoreIngredient_ = coreIngredient;
	}

	const std::string& GetPotionName() const { //이름 개터
		return PotionName_;
	}

	const std::string& GetCoreIngredient() const { //재료 개터
		return CoreIngredient_;
	}

private:
	std::string PotionName_;
	std::string CoreIngredient_;

};

class AlchemyWorkshop {
public:
	void AddRecipe(const std::string& potionName, const std::string& coreIngredient) {
		recipes_.push_back(PotionRecipe(potionName, coreIngredient));//앞의 인자를 받아 레시피의 뒤에 추가
	}
	void DisplayAllRecipes() const {
		for (const PotionRecipe& recipe : recipes_) {
			//std::cout << recipes_.GetPotionName() << " : " << recipes_.GetCoreIngredient() << std::endl;
			std::cout << recipe.GetPotionName() << " : " << recipe.GetCoreIngredient() << std::endl;
		} //이름이 아니라 인스턴스를 따라가야함
	}

	PotionRecipe SearchRecipeByName(const std::string& name) const {
		for (const PotionRecipe& recipe : recipes_) {
			if (recipe.GetPotionName() == name)
				return recipe; //반환 값 역시 마찬가지
		}
		return PotionRecipe("NONE", "NONE");

	}

	std::vector<PotionRecipe> SearchRecipeByIngredient(const std::string& ingredient) const {
		std::vector<PotionRecipe> ret;//새로운 레시피 백터 생성
		for (const PotionRecipe& recipe : recipes_) {		//기록 되어있는 레시피와 비교
			if (recipe.GetCoreIngredient() == ingredient) { //재료가 입력된 재료와 같다면
				ret.push_back(recipe);						//해당 재료를 마지막에 추가
			}
		}
		return ret;//반환값 추가
	}

private:
	std::vector<PotionRecipe> recipes_;
};


int main() {
	AlchemyWorkshop workshop; //인스턴스 생성
	// 레시피 추가
	workshop.AddRecipe("Healing Potion","Herb");
	workshop.AddRecipe("Mana Potion", "Magic Water");
	workshop.AddRecipe("Stamina Potion", "Herb");
	workshop.AddRecipe("Fire Resistance Potion", "Fire Flower");

	// 입력된 전체 레시피 출력
	workshop.DisplayAllRecipes();

	//이름으로 레시피 검색
	PotionRecipe recipe = workshop.SearchRecipeByName("Mana Potion");
	std::cout << "검색된 레시피" << recipe.GetPotionName() << std::endl;

	//재료로 레시피 검색
	std::vector<PotionRecipe> herbRecipes = workshop.SearchRecipeByIngredient("Herb");

	std::cout << "Herb를 사용하는 레시피 수: " << herbRecipes.size() << std::endl;

	return 0;
}
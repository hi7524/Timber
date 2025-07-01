#pragma once

// 전역적으로 사용되는 정의들

enum class Origins
{
	TL, TC, TR,
	ML, MC, MR,
	BL, BC, BR,
	Custom		
};

enum class SceneIds
{
	None = -1,
	Game,
	Dev1,
	Dev2,
	Count // 이런식으로 많이 사용
};

enum class Sides
{
	Left,
	Right,
	None
};
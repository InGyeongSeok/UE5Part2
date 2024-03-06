// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ABAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UABAnimInstance();

protected:
	virtual void NativeInitializeAnimation() override; //AnimInstance가 처음 생성될 때 한 번 호출

	virtual void NativeUpdateAnimation(float DeltaSeconds) override; //매 프레임마다 호출 
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Character)
	TObjectPtr<class ACharacter> Owner; //AnimInstance를 소유하고 있는 캐릭터 정보 담는 변수

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Character)
	TObjectPtr<class UCharacterMovementComponent> Movement; //캐릭터의 움직임 정보 담는 변수

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	FVector Velocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	float GroundSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	uint8 bIsIdle : 1; //bool 타입은 사이즈 명확하지 않다 -> uint8로 선언하되 구분하기 위해서 접두사 붙이고 비트 플래그를 추가로 달아준다

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	float MovingThreshould; //움직이고 있는지 쉬고 있는지 판단하기 위한 변수

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	uint8 bIsFalling : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	uint8 bIsJumping : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	float JumpingThreshould; //점프중인지 아닌지 판단하기 위한 변수
};

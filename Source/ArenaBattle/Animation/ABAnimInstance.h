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
	virtual void NativeInitializeAnimation() override; //AnimInstance�� ó�� ������ �� �� �� ȣ��

	virtual void NativeUpdateAnimation(float DeltaSeconds) override; //�� �����Ӹ��� ȣ�� 
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Character)
	TObjectPtr<class ACharacter> Owner; //AnimInstance�� �����ϰ� �ִ� ĳ���� ���� ��� ����

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Character)
	TObjectPtr<class UCharacterMovementComponent> Movement; //ĳ������ ������ ���� ��� ����

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	FVector Velocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	float GroundSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	uint8 bIsIdle : 1; //bool Ÿ���� ������ ��Ȯ���� �ʴ� -> uint8�� �����ϵ� �����ϱ� ���ؼ� ���λ� ���̰� ��Ʈ �÷��׸� �߰��� �޾��ش�

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	float MovingThreshould; //�����̰� �ִ��� ���� �ִ��� �Ǵ��ϱ� ���� ����

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	uint8 bIsFalling : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	uint8 bIsJumping : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
	float JumpingThreshould; //���������� �ƴ��� �Ǵ��ϱ� ���� ����
};

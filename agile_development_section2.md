# Agile Design

agile 팀은 각 iteration에서 시스템의 설계를 개선해 지금 그대로도 충분히 좋은 시스템이 되도록 한다.  

미래의 요구사항, 내일 필요한 infrastructure가 아닌, 현재의 시스템 설계에 초점을 두고 더욱 개선하기 위해 노력한다.

## Symptoms of Poor Design 

설계가 잘못됐을때 나타나는 증상을 열거하고 설명한다.  
소프트웨어 프로젝트에서 어떻게 이런 증상이 축적 될 수 있는지  
이것을 피하기 위한 방법이 무엇이 있는지 알아본다  

- Rigidity : The design is hard to change
- Fragility : The design is easy to break
- Immobility : The design is hard to reuse
- Viscosity : Is is hard to do the right thing
- Needless Complexity : Overdesign
- Needless Repetition : Mouse abuse
- Opacity : Disorganized expression

## principle
#### 최적의 설계를 구성할 수 있도록 돕는, 객체 지향 설계 원칙들

1. SRP : Single Responsibility Principle
2. OCP : Open-Closed Principle
3. LSP : Liskov Substituion Principle
4. DIP : Dependency Inversion Principle
5. ISP : Interface Segregation Principle

#### agile 팀은 소프트웨어가 부패하도록 내버려두지 않는다

시스템의 설계를 가능한 한 명료하고 단순하게 유지하고, 이것을 많은 단위 테스트와, 인수 테스트로 뒷받침한다.  
이런 작업을 통해 설계를 유연하고 변형하기 쉬운 것으로 유지할 수 있다.
## SRP (단일 책임 원칙)
cohesion (응집도) : 모듈이나 클래스의 변경을 야기하는 응집력에 대해 얘기해본다.  
## OCP (개방 폐쇄 원칙)
소프트웨어 개체는 확장에 대해 열려 있어야 하고, 수정에 대해서는 닫혀 있어야 한다.

1. 확장에 대해 열려 있다.  
   이것은 모듈의 행위가 확장될 수 있음을 의미한다. 애플리케이션의 요구사항이 변경될 때, 이 변경에 맞게 새로운 행위를 추가해 모듈을 확장할 수 있다.  
   즉, 모듈이 하는 일을 변경할 수 있다.  
2. 수정에 대해 닫혀 있다.  
   어떤 모듈의 행위를 확장하는 것이 그 모듈의 소스 코드나 바이너리 코드의 변경을 초래하지 않는다.  

#### 어떤 모듈의 소스 코드를 변경하지 않고도 그 모듈의 행위를 바꾸는 일이 어떻게 가능한가? 어떻게 모듈을 변경하지 않은 채로, 그 모듈이 하는 일을 변경할 수 있을까?
#### 해결책은 추상화다. 모듈은 추상화를 조작할 수 있다. 이런 모듈은 고정된 추상화에 의존하기 때문에 수정에 대해 닫혀 있을 수 있다. 그 모듈의 행위는 추상화의 새 파생 클래스들을 만듦으로써 확장이 가능하다.


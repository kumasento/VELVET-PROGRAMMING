class Animal { val sound = "rustle" }
class Bird extends Animal { override val sound = "call" }
class Chicken extends Bird { override val sound = "cluck" }

def biophony[T <: Animal](things: Seq[T]) = things.map(_.sound)

def hashcodes(l: Seq[_ <: AnyRef]) = l.map(_.hashCode)

object TypesnPoly {
	def main(args: Array[String]): Unit = {
		val getTweet: (Bird => String) = ((a:Animal) => a.sound)
		val hatch: (() => Bird) = (() => new Chicken )
		val animal = new Animal
		val bird = new Bird
		println("getTweet Animal: " + getTweet(bird))
		println("hatch " + hatch())

		val manyAnimals = animal :: List(bird)
		println("Animal Sounds for " + manyAnimals + " are " + biophony(manyAnimals))
		
		println(hashcodes(List("a", "b")))
	}
}
TypesnPoly.main(Array())
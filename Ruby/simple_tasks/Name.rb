class Name
  def initialize(f_n,m_n,h_a)
    @full = f_n + " " + m_n
    @c_to_full=f_n
    @age=h_a
    @film=nil

  end
  def print
    if (@age<60)
      puts "#{@c_to_full} \n#{@age} - young "
    elsif (@age>=60)
      puts "#{@full} \n#{@age} - old"
    end
  end
  def full
    @full
  end
  def film=(film)
    @film = film
  end

  def film
    return @film
  end
end
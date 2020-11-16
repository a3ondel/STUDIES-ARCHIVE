/* MIT License

Copyright (c) 2016 JetBrains http://www.jetbrains.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */

using System;
// ReSharper disable InheritdocConsiderUsage

#pragma warning disable 1591
// ReSharper disable UnusedMember.Global
// ReSharper disable MemberCanBePrivate.Global
// ReSharper disable UnusedAutoPropertyAccessor.Global
// ReSharper disable IntroduceOptionalParameters.Global
// ReSharper disable MemberCanBeProtected.Global
// ReSharper disable InconsistentNaming

namespace RestaurantManager.Annotations
{
  /// <summary>
  /// Indicates that the value of the marked element could be <c>null</c> sometimes,
  /// so checking for <c>null</c> is required before its usage.
  /// </summary>
  /// <example><code>
  /// [CanBeNull] object Test() => null;
  /// 
  /// void UseTest() {
  ///   var p = Test();
  ///   var s = p.ToString(); // Warning: Possible 'System.NullReferenceException'
  /// }
  /// </code></example>
  [AttributeUsage(
    AttributeTargets.Method | AttributeTargets.Parameter | AttributeTargets.Property |
    AttributeTargets.Delegate | AttributeTargets.Field | AttributeTargets.Event |
    AttributeTargets.Class | AttributeTargets.Interface | AttributeTargets.GenericParameter)]
  public sealed class CanBeNullAttribute : Attribute { }

  /// <summary>
  /// Indicates that the value of the marked element can never be <c>null</c>.
  /// </summary>
  /// <example><code>
  /// [NotNull] object Foo() {
  ///   return null; // Warning: Possible 'null' assignment
  /// }
  /// </code></example>
  [AttributeUsage(
    AttributeTargets.Method | AttributeTargets.Parameter | AttributeTargets.Property |
    AttributeTargets.Delegate | AttributeTargets.Field | AttributeTargets.Event |
    AttributeTargets.Class | AttributeTargets.Interface | AttributeTargets.GenericParameter)]
  public sealed class NotNullAttribute : Attribute { }

  /// <summary>
  /// Can be applied to symbols of types derived from IEnumerable as well as to symbols of Task
  /// and Lazy classes to indicate that the value of a collection item, of the Task.Result property
  /// or of the Lazy.Value property can never be null.
  /// </summary>
  /// <example><code>
  /// public void Foo([ItemNotNull]List&lt;string&gt; books)
  /// {
  ///   foreach (var book in books) {
  ///     if (book != null) // Warning: Expression is always true
  ///      Console.WriteLine(book.ToUpper());
  ///   }
  /// }
  /// </code></example>
  [AttributeUsage(
    AttributeTargets.Method | AttributeTargets.Parameter | AttributeTargets.Property |
    AttributeTargets.Delegate | AttributeTargets.Field)]
  public sealed class ItemNotNullAttribute : Attribute { }

  /// <summary>
  /// Can be applied to symbols of types derived from IEnumerable as well as to symbols of Task
  /// and Lazy classes to indicate that the value of a collection item, of the Task.Result property
  /// or of the Lazy.Value property can be null.
  /// </summary>
  /// <example><code>
  /// public void Foo([ItemCanBeNull]List&lt;string&gt; books)
  /// {
  ///   foreach (var book in books)
  ///   {
  ///     // Warning: Possible 'System.NullReferenceException'
  ///     Console.WriteLine(book.ToUpper());
  ///   }
  /// }
  /// </code></example>
  [AttributeUsage(
    AttributeTargets.Method | AttributeTargets.Parameter | AttributeTargets.Property |
    AttributeTargets.Delegate | AttributeTargets.Field)]
  public sealed class ItemCanBeNullAttribute : Attribute { }

  /// <summary>
  /// Indicates that the marked method builds string by the format pattern and (optional) arguments.
  /// The parameter, which contains the format string, should be given in constructor. The format string
  /// should be in <see cref="string.Format(IFormatProvider,string,object[])"/>-like form.
  /// </summary>
  /// <example><code>
  /// [StringFormatMethod("message")]
  /// void ShowError(string message, params object[] args) { /* do something */ }
  /// 
  /// void Foo() {
  ///   ShowError("Failed: {0}"); // Warning: Non-existing argument in format string
  /// }
  /// </code></example>
  [AttributeUsage(
    AttributeTargets.Constructor | AttributeTargets.Method |
    AttributeTargets.Property | AttributeTargets.Delegate)]
  public sealed class StringFormatMethodAttribute : Attribute
  {
    /// <param name="formatParameterName">
    /// Specifies which parameter of an annotated method should be treated as the format string
    /// </param>
    public StringFormatMethodAttribute([NotNull] string formatParameterName)
    {
      FormatParameterName = formatParameterName;
    }

    [NotNull] public string FormatParameterName { get; }
  }

  /// <summary>
  /// Use this annotation to specify a type that contains static or const fields
  /// with values for the annotated property/field/parameter.
  /// The specified type will be used to improve completion suggestions.
  /// </summary>
  /// <example><code>
  /// namespace TestNamespace
  /// {
  ///   public class Constants
  ///   {
  ///     public static int INT_CONST = 1;
  ///     public const string STRING_CONST = "1";
  ///   }
  ///
  ///   public class Class1
  ///   {
  ///     [ValueProvider("TestNamespace.Constants")] public int myField;
  ///     public void Foo([ValueProvider("TestNamespace.Constants")] string str) { }
  ///
  ///     public void Test()
  ///     {
  ///       Foo(/*try completion here*/);//
  ///       myField = /*try completion here*/
  ///     }
  ///   }
  /// }
  /// </code></example>
  [AttributeUsage(
    AttributeTargets.Parameter | AttributeTargets.Property | AttributeTargets.Field,
    AllowMultiple = true)]
  public sealed class ValueProviderAttribute : Attribute
  {
    public ValueProviderAttribute([NotNull] string name)
    {
      Name = name;
    }

    [NotNull] public string Name { get; }
  }

  /// <summary>
  /// Indicates that the integral value falls into the specified interval.
  /// It's allowed to specify multiple non-intersecting intervals.
  /// Values of interval boundaries are inclusive.
  /// </summary>
  /// <example><code>
  /// void Foo([ValueRange(0, 100)] int value) {
  ///   if (value == -1) { // Warning: Expression is always 'false'
  ///     ...
  ///   }
  /// }
  /// </code></example>
  [AttributeUsage(
    AttributeTargets.Parameter | AttributeTargets.Field | AttributeTargets.Property |
    AttributeTargets.Method | AttributeTargets.Delegate,
    AllowMultiple = true)]
  public sealed class ValueRangeAttribute : Attribute
  {
    public object From { get; }
    public object To { get; }

    public ValueRangeAttribute(long from, long to)
    {
      From = from;
      To = to;
    }

    public ValueRangeAttribute(ulong from, ulong to)
    {
      From = from;
      To = to;
    }

    public ValueRangeAttribute(long value)
    {
      From = To = value;
    }

    public ValueRangeAttribute(ulong value)
    {
      From = To = value;
    }
  }

  /// <summary>
  /// Indicates that the integral value never falls below zero.
  /// </summary>
  /// <example><code>
  /// void Foo([NonNegativeValue] int value) {
  ///   if (value == -1) { // Warning: Expression is always 'false'
  ///     ...
  ///   }
  /// }
  /// </code></example>
  [AttributeUsage(
    AttributeTargets.Parameter | AttributeTargets.Field | AttributeTargets.Property |
    AttributeTargets.Method | AttributeTargets.Delegate)]
  public sealed class NonNegativeValueAttribute : Attribute { }

  /// <summary>
  /// Indicates that the function argument should be a string literal and match one
  /// of the parameters of the caller function. For example, ReSharper annotates
  /// the parameter of <see cref="System.ArgumentNullException"/>.
  /// </summary>
  /// <example><code>
  /// void Foo(string param) {
  ///   if (param == null)
  ///     throw new ArgumentNullException("par"); // Warning: Cannot resolve symbol
  /// }
  /// </code></example>
  [AttributeUsage(AttributeTargets.Parameter)]
  public sealed class InvokerParameterNameAttribute : Attribute { }

  /// <summary>
  /// Indicates that the method is contained in a type that implements
  /// <c>System.ComponentModel.INotifyPropertyChanged</c> interface and this method
  /// is used to notify that some property value changed.
  /// </summary>
  /// <remarks>
  /// The method should be non-static and conform to one of the supported signatures:
  /// <list>
  /// <item><c>NotifyChanged(string)</c></item>
  /// <item><c>NotifyChanged(params string[])</c></item>
  /// <item><c>NotifyChanged{T}(Expression{Func{T}})</c></item>
  /// <item><c>NotifyChanged{T,U}(Expression{Func{T,U}})</c></item>
  /// <item><c>SetProperty{T}(ref T, T, string)</c></item>
  /// </list>
  /// </remarks>
  /// <example><code>
  /// public class Foo : INotifyPropertyChanged {
  ///   public event PropertyChangedEventHandler PropertyChanged;
  /// 
  ///   [NotifyPropertyChangedInvocator]
  ///   protected virtual void NotifyChanged(string propertyName) { ... }
  ///
  ///   string _name;
  /// 
  ///   public string Name {
  ///     get { return _name; }
  ///     set { _name = value; NotifyChanged("LastName"); /* Warning */ }
  ///   }
  /// }
  /// </code>
  /// Examples of generated notifications:
  /// <list>
  /// <item><c>NotifyChanged("Property")</c></item>
  /// <item><c>NotifyChanged(() =&gt; Property)</c></item>
  /// <item><c>NotifyChanged((VM x) =&gt; x.Property)</c></item>
  /// <item><c>SetProperty(ref myField, value, "Property")</c></item>
  /// </list>
  /// </example>
  [AttributeUsage(AttributeTargets.Method)]
  public sealed class NotifyPropertyChangedInvocatorAttribute : Attribute
  {
    public NotifyPropertyChangedInvocatorAttribute() { }
    public NotifyPropertyChangedInvocatorAttribute([NotNull] string parameterName)
    {
      ParameterName = parameterName;
    }

    [CanBeNull] public string ParameterName { get; }
  }
}